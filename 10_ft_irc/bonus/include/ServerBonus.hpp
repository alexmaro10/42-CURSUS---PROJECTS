#ifndef SERVER_HPP_BONUS
#define SERVER_HPP_BONUS

#include "ChannelManagerBonus.hpp"
#include "CommandHandlerBonus.hpp"
#include "UserManagerBonus.hpp"

#include <csignal>
#include <string>
#include <sys/select.h>

class Server
{
public:
	Server(int port, const std::string &password);
	~Server();

	void run(const volatile sig_atomic_t &stopFlag);

private:
	int _port;
	int _listenFd;
	UserManager _users;
	ChannelManager _channels;
	CommandHandler _commands;

	void setupSocket();
	void closeAll();

	void acceptClient();
	void removeClient(int fd, const std::string &reason);

	void handleClientData(int fd);
	void processLines(User &user);
	void buildReadSet(fd_set &readFds, int &maxFd) const;
};

#endif
