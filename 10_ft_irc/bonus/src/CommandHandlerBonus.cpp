#include <set>


#include "CommandHandlerBonus.hpp"
#include "ErrorRepliesBonus.hpp"
#include "MessageBonus.hpp"

#include <algorithm>
#include <cerrno>
#include <cstring>
#include <iostream>
#include <sstream>
#include <sys/socket.h>

CommandHandler::CommandHandler(const std::string &password, ChannelManager &channels)
	: _password(password), _channels(channels)
{
}

bool CommandHandler::handleLine(User &user, UserManager &users, const Message &msg, std::string &disconnectReason) const
{
	disconnectReason.clear();
	const std::map<std::string, Channel> &channels = _channels.getChannels();
	std::string cmd = upper(msg.getCommand());
	if (cmd.empty()) {
		if (msg.isValid() && !msg.getTrailing().empty()) {
			if (user.channelCount == 0 && user.welcomed) {
					sendRaw(user.fd, ErrorReplies::unknownCommand(msg.getTrailing()));
			}
			else
			{
				for (std::map<std::string, Channel>::const_iterator it = channels.begin();
					it != channels.end();
					++it)
				{
					const Channel &channel = it->second;
					if (!channel.hasMember(user.fd))
						continue;
					const std::set<int> &members = channel.getMemberFds();
					for (std::set<int>::const_iterator mit = members.begin();
						mit != members.end();
						++mit)
					{
						int targetFd = *mit;
						std::string prefix = user.nickname + "!" + user.username + "@localhost";
						sendRaw(targetFd,
								":" + prefix + " PRIVMSG " + channel.name() + " :" + msg.getTrailing());
					}
				}
			}
		}
		return false;
	}

	std::ostringstream oss;
	for (size_t i = 0; i < msg.getParams().size(); ++i) {
		if (i > 0) oss << " ";
		oss << msg.getParams()[i];
	}
	if (msg.hasTrailing()) {
		if (!msg.getParams().empty()) oss << " ";
		oss << ":" << msg.getTrailing();
	}
	std::istringstream iss(oss.str());

	if (dispatchCommand(cmd, user, users, _channels, iss, disconnectReason))
		return !disconnectReason.empty();
	if (!user.passOk)
	{
		sendRaw(user.fd, ErrorReplies::notRegistered());
		return false;
	}
	return false;
}

bool CommandHandler::dispatchCommand(const std::string &cmd, User &user, UserManager &users, ChannelManager &channels, std::istringstream &iss, std::string &disconnectReason) const
{
	if (cmd == "PASS")
		return handlePass(user, iss);
	if (cmd == "JOIN")
		return handleJoin(user, users, channels, iss);
	if (cmd == "KICK")
		return handleKick(user, users, channels, iss);
	if (cmd == "NICK")
		return handleNick(user, users, iss);
	if (cmd == "USER")
		return handleUser(user, iss);
	if (cmd == "PING")
		return handlePing(user, iss);
	if (cmd == "PRIVMSG" || cmd == "NOTICE")
		return handlePrivMsg(user, users, iss);
	if (cmd == "TOPIC")
		return handleTopic(user, iss);
	if (cmd == "QUIT")
		return handleQuit(disconnectReason);
	if (cmd == "INVITE")
		return handleInvite(user, users, iss);
	if (cmd == "MODE")
		return handleMode(user, users, iss);
	if (cmd == "BOT")
		return handleBot(user, iss);
	sendRaw(user.fd, ErrorReplies::unknownCommand(cmd));
	return false;
}

std::string CommandHandler::trimCrlf(const std::string &s)
{
	std::string out = s;
	while (!out.empty() && (out[out.size() - 1] == '\r' || out[out.size() - 1] == '\n'))
		out.erase(out.size() - 1);
	return out;
}

std::string CommandHandler::upper(const std::string &s)
{
	std::string out = s;
	std::transform(out.begin(), out.end(), out.begin(), ::toupper);
	return out;
}

bool CommandHandler::isRegistrationComplete(const User &user)
{
	return user.passOk && !user.nickname.empty() && !user.username.empty();
}

void CommandHandler::maybeSendWelcome(User &user) const
{
	if (user.welcomed || !isRegistrationComplete(user))
		return;

	user.welcomed = true;
	sendNumeric(user.fd, "001", user.nickname + " :Welcome to ft_irc!");
	sendNotice(user.fd, user.nickname, "You are registered.");
}

void CommandHandler::sendRaw(int fd, const std::string &message) const
{
	std::string out = message;
	if (out.size() < 2 || out.substr(out.size() - 2) != "\r\n")
		out += "\r\n";
	if (send(fd, out.c_str(), out.size(), 0) < 0)
		std::cerr << "send failed on fd=" << fd << ": " << std::strerror(errno) << std::endl;
}

void CommandHandler::sendNotice(int fd, const std::string &target, const std::string &text) const
{
	sendRaw(fd, ":ft_irc NOTICE " + target + " :" + text);
}

void CommandHandler::sendNumeric(int fd, const std::string &code, const std::string &text) const
{
	sendRaw(fd, ":ft_irc " + code + " " + text);
}

bool CommandHandler::isKnownCommand(const std::string &cmd)
{
	static const char* knownCmds[] = {"PASS", "NICK", "USER", "PING", "QUIT", "JOIN", "PART", "PRIVMSG", "NOTICE", "KICK", "TOPIC", "MODE", "INVITE", "BOT"};
	for (size_t i = 0; i < sizeof(knownCmds)/sizeof(knownCmds[0]); ++i) {
		if (cmd == knownCmds[i])
			return true;
	}
	return false;
}