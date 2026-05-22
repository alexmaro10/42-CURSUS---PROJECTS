#include "CommandHandlerBonus.hpp"
#include "ErrorRepliesBonus.hpp"

#include <sstream>
#include <iostream>

static size_t countChannels(std::string chanName)
{
	size_t count;

	count = 0;
	for (size_t i = 0; i < chanName.length(); i++)
	{
		if (count > 0)
		{
			if (chanName[i - 1] == ',')
			count++;
		}
		else
			count++;
	}
	return count;
}

void ft_split(const std::string& input, std::string res[], int n)
{
	std::string actual;
	int idx = 0;

	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] == ',') {
			if (idx < n) {
				res[idx++] = actual;
				actual.clear();
			}
		} else {
			actual += input[i];
		}
	}
	
	if (!actual.empty() && idx < n) {
		res[idx++] = actual;
	}
}

bool CommandHandler::checkInviteMode(User &user, Channel &channel, std::string chanName) const
{
	if (channel.isInviteOnly())
	{
		if (!channel.isInvited(user.fd))
		{
			sendRaw(user.fd, ErrorReplies::inviteOnlyChan(user.getNick(), chanName));
			return false;
		}
	}
	return true;
}

bool CommandHandler::checkPassMode(Channel &channel, std::string chanName, User &user, std::string pass) const
{
	if (channel.hasKey())
	{
		if (pass.empty())
		{
			sendRaw(user.fd, ErrorReplies::badChannelKey(user.getNick(), chanName));
			return false;
		}
		if (pass != channel.getKey())
		{
			sendRaw(user.fd, ErrorReplies::badChannelKey(user.getNick(), chanName));
			return false;
		}
	}
	return true;
}

bool CommandHandler::checkPassModeMulti(Channel &channel, std::string chanName, User &user, std::string pass[], int passIndex, size_t n) const
{
	if (channel.hasKey())
	{
		if (passIndex < 0 || passIndex >= (int)n) 
		{
			sendRaw(user.fd, ErrorReplies::badChannelKey(user.getNick(), chanName));
			return false;
		}

		if (pass[passIndex].empty())
		{
			sendRaw(user.fd, ErrorReplies::badChannelKey(user.getNick(), chanName));
			return false;
		}

		if (pass[passIndex] != channel.getKey())
		{
			sendRaw(user.fd, ErrorReplies::badChannelKey(user.getNick(), chanName));
			return false;
		}
	}

	return true;
}

bool CommandHandler::checkLimitMode(Channel &channel, std::string chanName, User &user) const
{
	if (channel.hasUserLimit())
	{
		if (channel.nMembers() + 1 > channel.getUserLimit())
		{
			sendRaw(user.fd, ErrorReplies::channelIsFull(user.getNick(), chanName));
			return false;
		}
	}
	return true;
}

bool CommandHandler::multiHandleJoin(User &user, UserManager &users, ChannelManager &channels, size_t numberOfChannels, std::string chanName, std::string pass) const
{

	std::string chansNames[numberOfChannels];
	ft_split(chanName, chansNames, numberOfChannels);
	int passIndex = -1;
	for (size_t i = 0; i < numberOfChannels; i++)
	{
		if (chansNames[i][0] != '#')
		{
			sendRaw(user.fd, ErrorReplies::noSuchChannel(chansNames[i]));
			continue;
		}
		bool isNewChannel = !channels.has(chansNames[i]);

		Channel &channel = channels.getOrCreate(chansNames[i]);
		if (isNewChannel)
		{
			channel.addOperator(user.fd);
			channel.addMember(user.fd);
		}
		else
		{
			if (channel.hasKey())
				passIndex++;

			if (channel.hasMember(user.fd))
			{
				sendRaw(user.fd, ErrorReplies::userAlreadyOnChannel(user.getNick(), chansNames[i]));
				continue;
			}
			std::string passA[numberOfChannels];
			if (!pass.empty())
			{
				ft_split(pass, passA, numberOfChannels);
			}
			if (checkInviteMode(user, channel, chanName) && checkPassModeMulti(channel, chanName, user, passA, passIndex, numberOfChannels) && checkLimitMode(channel, chanName, user))
			{
				channel.addMember(user.fd);
				if (channel.isInvited(user.fd))
					channel.removeInvite(user.fd);
			}
			else
				continue ;
		}
		user.channelCount++;
		std::string joinMsg = ":" + user.nickname + "!" + user.username + "@" + user.ip + " JOIN " + chansNames[i] + "\r\n";
		const std::set<int> &members = channel.getMemberFds();
		for (std::set<int>::const_iterator it = members.begin(); it != members.end(); ++it)
		{
			sendRaw(*it, joinMsg);
		}
		std::string nameReply = ":ft_irc 353 " + user.nickname + " = " + chansNames[i] + " :";
		for (std::set<int>::const_iterator it = members.begin(); it != members.end(); ++it) {
			User *m = users.get(*it);
			if (m) {
				if (channel.isOperator(m->fd)) {
					nameReply += "@";
				}
				nameReply += m->nickname + " ";
			}
		}
		nameReply += "\r\n";
		sendRaw(user.fd, nameReply);

		sendRaw(user.fd, ":ft_irc 366 " + user.nickname + " " + chansNames[i] + " :End of /NAMES list\r\n");
	}
	
	return true;
}

bool CommandHandler::handleJoin(User &user, UserManager &users, ChannelManager &channels, std::istringstream &iss) const
{
	std::string chanName;
	std::string pass;
	size_t numberOfChannels;

	iss >> chanName;
	iss >> pass;

	if (!isRegistrationComplete(user)) {
		sendRaw(user.fd, ErrorReplies::notRegistered());
		return true;
	}

	if (chanName.empty()) {
		sendRaw(user.fd, ErrorReplies::needMoreParams("JOIN"));
		return true;
	}

	if (chanName[0] != '#') {
		sendRaw(user.fd, ErrorReplies::noSuchChannel(chanName));
		return true;
	}

	numberOfChannels = countChannels(chanName);
	if (numberOfChannels == 1)
	{
		bool isNewChannel = !channels.has(chanName);

		Channel &channel = channels.getOrCreate(chanName);
		if (isNewChannel)
		{
			channel.addMember(user.fd);
			channel.addOperator(user.fd);
		}
		else
		{
			if (channel.hasMember(user.fd))
			{
				sendRaw(user.fd, ErrorReplies::userAlreadyOnChannel(user.getNick(), chanName));
				return true;
			}
			if (checkInviteMode(user, channel, chanName) && checkPassMode(channel, chanName, user, pass) && checkLimitMode(channel, chanName, user))
			{
				channel.addMember(user.fd);
				if (channel.isInvited(user.fd))
					channel.removeInvite(user.fd);
			}
			else
				return true;
		}
		user.channelCount++;

		std::string joinMsg = ":" + user.nickname + "!" + user.username + "@" + user.ip + " JOIN " + chanName + "\r\n";

		const std::set<int> &members = channel.getMemberFds();
		for (std::set<int>::const_iterator it = members.begin(); it != members.end(); ++it) {
			sendRaw(*it, joinMsg);
		}

		std::string nameReply = ":ft_irc 353 " + user.nickname + " = " + chanName + " :";
		for (std::set<int>::const_iterator it = members.begin(); it != members.end(); ++it) {
			User *m = users.get(*it);
			if (m) {
				if (channel.isOperator(m->fd)) {
					nameReply += "@";
				}
				nameReply += m->nickname + " ";
			}
		}
		nameReply += "\r\n";
		sendRaw(user.fd, nameReply);

		sendRaw(user.fd, ":ft_irc 366 " + user.nickname + " " + chanName + " :End of /NAMES list\r\n");
		return true;
	}
	else if (numberOfChannels > 1)
	{
		return multiHandleJoin(user, users, channels, numberOfChannels, chanName, pass);
	}
	return true;
}