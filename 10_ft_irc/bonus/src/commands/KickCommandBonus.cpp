#include "CommandHandlerBonus.hpp"
#include "ErrorRepliesBonus.hpp"

#include <sstream>
#include <iostream>
#include <sys/socket.h>

bool CommandHandler::handleKick(User &user, UserManager &users, ChannelManager &channels, std::istringstream &iss) const
{
	std::string chanName;
	std::string kickUserName;
	int fd_kick;
	bool in_channel = false;

	fd_kick = 0;
	iss >> chanName;
	iss >> kickUserName;

	if (!isRegistrationComplete(user)) {
		sendRaw(user.fd, ErrorReplies::notRegistered());
		return true;
	}

	if (chanName.empty()) {
		sendRaw(user.fd, ErrorReplies::needMoreParams("KICK"));
		return true;
	}
	if (kickUserName.empty()) {
		sendRaw(user.fd, ErrorReplies::needMoreParams("KICK"));
		return true;
	}

	if (chanName[0] != '#') {
		sendRaw(user.fd, ErrorReplies::noSuchChannel(chanName));
		return true;
	}
	Channel *chns = channels.get(chanName);

	if (chns == NULL)
	{
		sendRaw(user.fd, ErrorReplies::noSuchChannel(chanName));
		return true;
	}

	if (chns->isOperator(user.fd) == false)
	{
		sendRaw(user.fd, ErrorReplies::userNotOperator());
		return true;
	}

	if (!users.isNicknameInUse(kickUserName, 0))
	{
		sendRaw(user.fd, ErrorReplies::noSuchNick(kickUserName));
		return true;
	}

	const std::set<int> &members = chns->getMemberFds();
	std::map<int, User> all_users = users.all();

	for (std::map<int, User>::const_iterator it = all_users.begin(); it != all_users.end(); ++it)
	{
		if (it->second.nickname == kickUserName)
		{
			fd_kick = it->first;
		}
	}
	for (std::set<int>::const_iterator it = members.begin(); it != members.end(); it++)
	{
		User *m = users.get(*it);
		if (m->fd == fd_kick)
		{
			in_channel = true;
		}
	}
	if (!in_channel)
	{
		sendRaw(user.fd, ErrorReplies::userNotOnChannel(kickUserName, chanName));
		return true;
	}
	std::string reason;
	std::string aux;
	iss >> aux;

	if (aux.empty())
	{
		std::string kickMsg = ":" + user.nickname + "!" + user.username + "@" + user.ip + " KICK " + chanName + " " + kickUserName + " :" + user.nickname + "\r\n";
		for (std::set<int>::const_iterator it = members.begin(); it != members.end(); ++it)
		{
			sendRaw(*it, kickMsg);
		}
		if (chns->nMembers() == 1)
		{
			User *kicked_user = users.get(fd_kick);
			if (kicked_user)
				kicked_user->channelCount--;
			chns->removeOperator(fd_kick);
			chns->removeMember(fd_kick);
			channels.removeIfEmpty(chanName);
			return true; 
		}
		if (chns->isOperator(fd_kick))
		{
			chns->removeOperator(fd_kick);
			chns->removeMember(fd_kick);
			int new_operatorFd = *chns->getMemberFds().begin();
			chns->addOperator(new_operatorFd);
			int newOp = *members.begin();
			const User* newOpUser = users.get(newOp);
			std::string opNick = newOpUser ? newOpUser->nickname : "(unknown)";

			std::string modeMsg = ":ft_irc MODE " + chns->name() + " +o " + opNick + "\r\n";
			for (std::set<int>::const_iterator mit = members.begin(); mit != members.end(); ++mit)
				send(*mit, modeMsg.c_str(), modeMsg.size(), 0);

			return true;
		}
		User *kicked_user = users.get(fd_kick);
		if (kicked_user)
			kicked_user->channelCount--;
		chns->removeMember(fd_kick);
		return true; 
	}
	if (aux[0] != ':')
	{
		sendRaw(user.fd, ErrorReplies::needMoreParams("KICK"));
		return true;
	}
	reason = reason + aux;
	while (iss >> aux)
		reason = reason + " " + aux;
	std::string kickMsg = ":" + user.nickname + "!" + user.username + "@" + user.ip + " KICK " + chanName + " " + kickUserName + " " + reason + "\r\n";
	for (std::set<int>::const_iterator it = members.begin(); it != members.end(); ++it)
	{
		sendRaw(*it, kickMsg);
	}
	if (chns->nMembers() == 1)
	{
		User *kicked_user = users.get(fd_kick);
		if (kicked_user)
			kicked_user->channelCount--;
		chns->removeOperator(fd_kick);
		chns->removeMember(fd_kick);
		channels.removeIfEmpty(chanName);
		return true; 
	}
	if (chns->isOperator(fd_kick))
	{
		chns->removeOperator(fd_kick);
		chns->removeMember(fd_kick);
		int new_operatorFd = *chns->getMemberFds().begin();
		chns->addOperator(new_operatorFd);
		int newOp = *members.begin();
		const User* newOpUser = users.get(newOp);
		std::string opNick = newOpUser ? newOpUser->nickname : "(unknown)";

		std::string modeMsg = ":ft_irc MODE " + chns->name() + " +o " + opNick + "\r\n";
		for (std::set<int>::const_iterator mit = members.begin(); mit != members.end(); ++mit) {
			send(*mit, modeMsg.c_str(), modeMsg.size(), 0);
		}
		return true;
	}
	User *kicked_user = users.get(fd_kick);
	if (kicked_user)
		kicked_user->channelCount--;
	chns->removeMember(fd_kick);
	return true; 
}

