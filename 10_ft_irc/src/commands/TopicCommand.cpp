
#include "CommandHandler.hpp"
#include "ErrorReplies.hpp"
#include "ChannelManager.hpp"
#include "Message.hpp"

#include <sstream>

bool	CommandHandler::handleTopic(User &user, std::istringstream &iss) const {
	std::string channel;
	iss >> channel;
	if (channel.empty())
	{
		sendRaw(user.fd, ErrorReplies::needMoreParams("TOPIC"));
		return true;
	}

	if (channel[0] != '#')
	{
		sendRaw(user.fd, ErrorReplies::noSuchChannel(channel));
		return true;
	}

	Channel *ch = _channels.get(channel);

	if (!ch)
	{
		sendRaw(user.fd, ErrorReplies::noSuchChannel(channel));
		return true;
	}

	std::string newTopic;
	std::getline(iss, newTopic);

	if (newTopic.empty())
	{
		if (ch->getTopic().empty())
			sendRaw(user.fd, ErrorReplies::noTopic(user.nickname, channel));
		else
			sendRaw(user.fd, Message::replyTopic(user.nickname, channel, ch->getTopic()));
		return true;
	}
	size_t	start = newTopic.find_first_not_of(' ');
	if (start != std::string::npos)
		newTopic = newTopic.substr(start);
	else
		newTopic.clear();

	if (!newTopic.empty() && newTopic[0] == ':')
		newTopic.erase(0, 1);

	if (!ch->hasMember(user.fd))
	{
		sendRaw(user.fd, ErrorReplies::notOnChannel(user.nickname, channel));
		return true;
	}

	if (ch->isTopicRestricted())
	{
		if (!ch->isOperator(user.fd))
		{
			sendRaw(user.fd, ErrorReplies::chanopPrivsNeeded(user.nickname, channel));
			return true;
		}
	}

	ch->setTopic(newTopic);
	const std::set<int>& members = ch->getMembers();
	std::set<int>::const_iterator it = members.begin();

	std::string msgAll = ":" + user.nickname + " TOPIC " + channel + " :" + newTopic + "\r\n";

	for (; it != members.end(); ++it)
	{
		int current_fd = *it;
		sendRaw(current_fd, msgAll);
	}
	return true;
}