#include "CommandHandler.hpp"
#include "ChannelManager.hpp"
#include "ErrorReplies.hpp"
#include "UserManager.hpp"

#include <sstream>

static void appendAppliedMode(std::string &modes, char &lastSign, bool adding, char modeChar)
{
	char sign = adding ? '+' : '-';
	if (lastSign != sign)
	{
		modes += sign;
		lastSign = sign;
	}
	modes += modeChar;
}

bool CommandHandler::handleMode(User &user, UserManager &users, std::istringstream &iss) const
{
	std::string channelName;
	iss >> channelName;
	if (channelName.empty())
	{
		sendRaw(user.fd, ErrorReplies::needMoreParams("MODE"));
		return true;
	}

	Channel *ch = _channels.get(channelName);
	if (!ch)
	{
		sendRaw(user.fd, ErrorReplies::noSuchChannel(channelName));
		return true;
	}

	std::string modeStr;
	iss >> modeStr;
	if (modeStr.empty())
	{
		if (!ch->hasMember(user.fd))
		{
			sendRaw(user.fd, ErrorReplies::notOnChannel(user.nickname, channelName));
			return true;
		}
		std::string modes = "+";
		std::string params;
		if (ch->isInviteOnly())
			modes += "i";
		if (ch->isTopicRestricted())
			modes += "t";
		if (ch->hasKey())
		{
			modes += "k";
			params += " " + ch->getKey();
		}
		if (ch->hasUserLimit())
		{
			modes += "l";
			std::ostringstream oss;
			oss << ch->getUserLimit();
			params += " " + oss.str();
		}
		sendRaw(user.fd, ":ft_irc 324 " + user.nickname + " " + channelName + " " + modes + params);
		sendNotice(user.fd, user.nickname, "Current modes for " + channelName + ": " + modes + params);
		return true;
	}

	if (!ch->hasMember(user.fd))
	{
		sendRaw(user.fd, ErrorReplies::notOnChannel(user.nickname, channelName));
		return true;
	}
	if (!ch->isOperator(user.fd))
	{
		sendRaw(user.fd, ErrorReplies::chanopPrivsNeeded(user.nickname, channelName));
		return true;
	}

	bool adding = true;
	std::string appliedModes;
	std::string appliedParams;
	char lastSign = '\0';

	for (size_t i = 0; i < modeStr.size(); ++i)
	{
		char modeChar = modeStr[i];
		if (modeChar == '+' || modeChar == '-')
		{
			adding = (modeChar == '+');
			continue;
		}

		if (modeChar == 'i')
		{
			if (ch->isInviteOnly() != adding)
			{
				ch->setInviteOnly(adding);
				appendAppliedMode(appliedModes, lastSign, adding, modeChar);
			}
			continue;
		}
		if (modeChar == 't')
		{
			if (ch->isTopicRestricted() != adding)
			{
				ch->setTopicRestricted(adding);
				appendAppliedMode(appliedModes, lastSign, adding, modeChar);
			}
			continue;
		}
		if (modeChar == 'k')
		{
			if (adding)
			{
				std::string key;
				if (!(iss >> key))
				{
					sendRaw(user.fd, ErrorReplies::needMoreParams("MODE"));
					return true;
				}
				if (!ch->hasKey() || ch->getKey() != key)
				{
					ch->setKey(key);
					appendAppliedMode(appliedModes, lastSign, true, modeChar);
					appliedParams += " " + key;
				}
			}
			else if (ch->hasKey())
			{
				ch->clearKey();
				appendAppliedMode(appliedModes, lastSign, false, modeChar);
			}
			continue;
		}
		if (modeChar == 'o')
		{
			std::string targetNick;
			if (!(iss >> targetNick))
			{
				sendRaw(user.fd, ErrorReplies::needMoreParams("MODE"));
				return true;
			}
			User *targetUser = users.getUserByNick(targetNick);
			if (!targetUser)
			{
				sendRaw(user.fd, ErrorReplies::noSuchNick(targetNick));
				return true;
			}
			if (!ch->hasMember(targetUser->fd))
			{
				sendRaw(user.fd, ErrorReplies::userNotInChannel(targetNick, channelName));
				return true;
			}
			if (adding && !ch->isOperator(targetUser->fd))
			{
				ch->addOperator(targetUser->fd);
				appendAppliedMode(appliedModes, lastSign, true, modeChar);
				appliedParams += " " + targetNick;
			}
			else if (!adding && ch->isOperator(targetUser->fd))
			{
				ch->removeOperator(targetUser->fd);
				appendAppliedMode(appliedModes, lastSign, false, modeChar);
				appliedParams += " " + targetNick;
			}
			continue;
		}
		if (modeChar == 'l')
		{
			if (adding)
			{
				std::string limitStr;
				if (!(iss >> limitStr))
				{
					sendRaw(user.fd, ErrorReplies::needMoreParams("MODE"));
					return true;
				}
				std::istringstream limitIss(limitStr);
				int limit = 0;
				if (!(limitIss >> limit) || limit <= 0)
				{
					sendRaw(user.fd, ErrorReplies::needMoreParams("MODE"));
					return true;
				}
				if (!ch->hasUserLimit() || ch->getUserLimit() != limit)
				{
					ch->setUserLimit(limit);
					appendAppliedMode(appliedModes, lastSign, true, modeChar);
					appliedParams += " " + limitStr;
				}
			}
			else if (ch->hasUserLimit())
			{
				ch->clearUserLimit();
				appendAppliedMode(appliedModes, lastSign, false, modeChar);
			}
			continue;
		}
	}

	if (!appliedModes.empty())
	{
		std::string msg = ":" + user.nickname + " MODE " + channelName + " " + appliedModes + appliedParams + "\r\n";
		const std::set<int> &members = ch->getMembers();
		std::set<int>::const_iterator it = members.begin();
		for (; it != members.end(); ++it)
			sendRaw(*it, msg);
		sendNotice(user.fd, user.nickname, "Modes updated on " + channelName + ": " + appliedModes + appliedParams);
	}
	return true;
}
