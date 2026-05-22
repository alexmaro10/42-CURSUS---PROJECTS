
#include "ServerBonus.hpp"
#include "MessageBonus.hpp"

#include <arpa/inet.h>
#include <cerrno>
#include <cstring>
#include <exception>
#include <fcntl.h>
#include <iostream>
#include <netinet/in.h>
#include <stdexcept>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

Server::Server(int port, const std::string &password)
	: _port(port), _listenFd(-1), _commands(password, _channels)
{
}

Server::~Server()
{
	closeAll();
}

void Server::run(const volatile sig_atomic_t &stopFlag)
{
	setupSocket();
	std::cout << "[ft_irc] Listening on port " << _port << std::endl;

	while (!stopFlag)
	{
		fd_set readFds;
		int maxFd = -1;
		buildReadSet(readFds, maxFd);

		struct timeval tv;
		tv.tv_sec = 1;
		tv.tv_usec = 0;

		int ready = select(maxFd + 1, &readFds, NULL, NULL, &tv);
		if (ready < 0)
		{
			if (errno == EINTR)
				continue;
			throw std::runtime_error(std::string("select failed: ") + std::strerror(errno));
		}
		if (ready == 0)
			continue;
		if (FD_ISSET(_listenFd, &readFds))
			acceptClient();
		std::map<int, User>::iterator curr = _users.all().begin();
		while (curr != _users.all().end())
		{
			int fd = curr->first;
			++curr;
			if (FD_ISSET(fd, &readFds))
				handleClientData(fd);
		}
	}

	std::cout << "[ft_irc] Shutting down." << std::endl;
}

void Server::buildReadSet(fd_set &readFds, int &maxFd) const
{
	FD_ZERO(&readFds);
	FD_SET(_listenFd, &readFds);
	maxFd = _listenFd;

	std::map<int, User>::const_iterator it = _users.all().begin();
	for (; it != _users.all().end(); ++it)
	{
		FD_SET(it->first, &readFds);
		if (it->first > maxFd)
			maxFd = it->first;
	}
}

void Server::setupSocket()
{
	_listenFd = socket(AF_INET, SOCK_STREAM, 6);
	if (_listenFd < 0)
		throw std::runtime_error(std::string("socket failed: ") + std::strerror(errno));
	
	fcntl(_listenFd, F_SETFL, O_NONBLOCK);
	
	int opt = 1;
	if (setsockopt(_listenFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
		throw std::runtime_error(std::string("setsockopt failed: ") + std::strerror(errno));
	struct sockaddr_in addr;
	std::memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(static_cast<uint16_t>(_port));
	if (bind(_listenFd, reinterpret_cast<struct sockaddr *>(&addr), sizeof(addr)) < 0)
		throw std::runtime_error(std::string("bind failed: ") + std::strerror(errno));
	if (listen(_listenFd, 42) < 0)
		throw std::runtime_error(std::string("listen failed: ") + std::strerror(errno));
}

void Server::closeAll()
{
	std::map<int, User>::iterator it = _users.all().begin();
	for (; it != _users.all().end(); ++it)
	{
		close(it->first);
	}
	_users.all().clear();
	if (_listenFd >= 0)
	{
		close(_listenFd);
		_listenFd = -1;
	}
}

void Server::acceptClient()
{
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	int fd = accept(_listenFd, reinterpret_cast<struct sockaddr *>(&addr), &len);

	if (fd < 0)
	{
		if (errno != EINTR && errno != EAGAIN && errno != EWOULDBLOCK)
		{
			std::cerr << "accept failed: " << std::strerror(errno) << std::endl;
		}
		return;
	}
	
	fcntl(fd, F_SETFL, O_NONBLOCK);
	
	_users.add(fd, inet_ntoa(addr.sin_addr));
	User *user = _users.get(fd);
	std::cout << "[ft_irc] Client connected: fd=" << fd << " ip=" << user->ip << std::endl;
	const std::string msg = ":ft_irc NOTICE AUTH :Welcome. Authenticate with PASS <password>\r\n";
	send(fd, msg.c_str(), msg.size(), 0);
}

void Server::removeClient(int fd, const std::string &reason)
{
	if (_users.has(fd))
	{
			const std::map<std::string, Channel> &channels = _channels.getChannels();
			for (std::map<std::string, Channel>::const_iterator it = channels.begin(); it != channels.end();)
			{
				std::map<std::string, Channel>::const_iterator next = it;
				++next;
				
				Channel *chan = _channels.get(it->first);
				if (chan && chan->hasMember(fd)) {
					bool wasOperator = chan->isOperator(fd);
					const User* quittingUser = _users.get(fd);
					std::string partNick = quittingUser ? quittingUser->nickname : "(unknown)";
					std::string partMsg = ":" + partNick + "!" + partNick + "@ft_irc PART " + chan->name() + " :Quit\r\n";
					const std::set<int> &members = chan->getMemberFds();
					for (std::set<int>::const_iterator mit = members.begin(); mit != members.end(); ++mit) {
						send(*mit, partMsg.c_str(), partMsg.size(), 0);
					}
					chan->removeMember(fd);
					if (!chan->empty() && wasOperator && chan->getOperators().count(fd) == 0) {
						if (chan->getOperators().empty()) {
							const std::set<int> &members = chan->getMemberFds();
							if (!members.empty()) {
								int newOp = *members.begin();
								chan->addOperator(newOp);
								const User* newOpUser = _users.get(newOp);
								std::string opNick = newOpUser ? newOpUser->nickname : "(unknown)";
								std::string modeMsg = ":ft_irc MODE " + chan->name() + " +o " + opNick + "\r\n";
								for (std::set<int>::const_iterator mit = members.begin(); mit != members.end(); ++mit) {
									send(*mit, modeMsg.c_str(), modeMsg.size(), 0);
								}
							}
						}
					}
					_channels.removeIfEmpty(it->first);
				}
				it = next;
			}
		std::cout << "[ft_irc] Client disconnected: fd=" << fd << " (" << reason << ")" << std::endl;
		close(fd);
		_users.remove(fd);
	}
}

void Server::handleClientData(int fd)
{
	User *user = _users.get(fd);
	if (user == NULL)
		return;
	char buffer[512];
	std::memset(buffer, 0, sizeof(buffer));
	ssize_t count = recv(fd, buffer, sizeof(buffer) - 1, 0);
	if (count <= 0)
	{
		removeClient(fd, count == 0 ? "connection closed" : std::strerror(errno));
		return;
	}
	user->recvBuffer.append(buffer, static_cast<size_t>(count));
	processLines(*user);
}

void Server::processLines(User &user)
{
	std::string::size_type pos = std::string::npos;
	while ((pos = user.recvBuffer.find('\n')) != std::string::npos)
	{
		std::string line = user.recvBuffer.substr(0, pos);
		user.recvBuffer.erase(0, pos + 1);
		line = CommandHandler::trimCrlf(line);
		if (line.empty())
			continue;

		Message msg(line);
		if (!msg.isValid()) {
			continue;
		}

		std::string disconnectReason;
		if (_commands.handleLine(user, _users, msg, disconnectReason))
		{
			removeClient(user.fd, disconnectReason);
			return;
		}
		if (!_users.has(user.fd))
			return;
	}
}
