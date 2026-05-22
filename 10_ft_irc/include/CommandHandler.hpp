#ifndef COMMANDHANDLER_HPP
#define COMMANDHANDLER_HPP

#include "UserManager.hpp"
#include "ChannelManager.hpp"

#include <sstream>
#include <string>

class Message;

class CommandHandler
{

public:
	CommandHandler(const std::string &password, ChannelManager &channels);

	bool handleLine(User &user, UserManager &users, const Message &msg, std::string &disconnectReason) const;
	static std::string trimCrlf(const std::string &s);
	static bool isKnownCommand(const std::string &cmd);
	void sendNotice(int fd, const std::string &target, const std::string &text) const;

private:
	std::string _password;
	ChannelManager	&_channels;

	bool dispatchCommand(const std::string &cmd, User &user, UserManager &users, ChannelManager &channels, std::istringstream &iss, std::string &disconnectReason) const;
	bool handlePass(User &user, std::istringstream &iss) const;
	bool handleJoin(User &user, UserManager &users, ChannelManager &channels, std::istringstream &iss) const;
	bool multiHandleJoin(User &user, UserManager &users, ChannelManager &channels, size_t numberOfChannels, std::string chanName, std::string pass) const;
	bool checkInviteMode(User &user, Channel &channel, std::string chanName) const;
	bool checkPassMode(Channel &channel, std::string chanName, User &user, std::string pass) const;
	bool checkPassModeMulti(Channel &channel, std::string chanName, User &user, std::string pass[], int passIndex, size_t n) const;
	bool checkLimitMode(Channel &channel, std::string chanName, User &user) const;
	bool handleKick(User &user, UserManager &users, ChannelManager &channels, std::istringstream &iss) const;
	bool handleNick(User &user, UserManager &users, std::istringstream &iss) const;
	bool handleUser(User &user, std::istringstream &iss) const;
	bool handlePing(User &user, std::istringstream &iss) const;
	bool handleQuit(std::string &disconnectReason) const;
	void handleUnknown(User &user, const std::string &cmd) const;
	bool handlePrivMsg(User &sender, UserManager &users, std::istringstream &iss) const;
	bool handleTopic(User &user, std::istringstream &iss) const;
	bool handleInvite(User &user, UserManager &users, std::istringstream &iss) const;
	bool handleMode(User &user, UserManager &users, std::istringstream &iss) const;

	static std::string upper(const std::string &s);
	static bool isRegistrationComplete(const User &user);

	void maybeSendWelcome(User &user) const;
	void sendRaw(int fd, const std::string &message) const;
	void sendNumeric(int fd, const std::string &code, const std::string &text) const;
};

#endif
