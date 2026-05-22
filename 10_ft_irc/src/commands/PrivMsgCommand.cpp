#include "CommandHandler.hpp"
#include "ErrorReplies.hpp"
#include "UserManager.hpp"
#include "ChannelManager.hpp"

#include <set>
#include <sstream>
#include <vector>


bool	CommandHandler::handlePrivMsg(User &user, UserManager &users, std::istringstream &iss) const
{
	std::string targets;
	iss >> targets;
	if (targets.empty())
	{
		sendRaw(user.fd, ErrorReplies::needMoreParams("PRIVMSG"));
		return true;
	}

	std::vector<std::string> list;
	std::stringstream ss(targets);
	std::string target;

	while (std::getline(ss, target, ','))
		list.push_back(target);


	std::string rest;
	std::getline(iss, rest);
	if (rest.empty())
	{
		sendRaw(user.fd, ErrorReplies::noTextToSend());
		return true;
	}

	size_t	start = rest.find_first_not_of(' ');
	if (start == std::string::npos)
	{
		sendRaw(user.fd, ErrorReplies::noTextToSend());
		return true;
	}
	rest = rest.substr(start);
	if (!rest.empty() && rest[0] == ':')
		rest.erase(0, 1);

	for (size_t i = 0; i <list.size(); i++)
	{
		std::string temp = list[i];

		std::string prefix = user.nickname + "!" + user.username + "@localhost";
		std::string msg = ":" + prefix +
						" PRIVMSG " + temp + 
						" :" + rest + "\r\n";
	
		if (temp[0] == '#')
		{
			Channel *ch =_channels.get(temp);
			if (!ch)
			{
				sendRaw(user.fd, ErrorReplies::noSuchChannel(temp));
				continue;
			}
			if (!ch->hasMember(user.fd))
			{
				sendRaw(user.fd, ErrorReplies::notOnChannel(user.nickname, temp));
				continue;
			}
			
			const std::set<int> &members = ch->getMembers();

			for (std::set<int>::const_iterator it = members.begin(); it != members.end(); ++it)
			{
				int fd = *it;
				sendRaw(fd, msg);
			}
		}
		else
		{
			User *receiver = users.getUserByNick(temp);
			if (!receiver)
			{
				sendRaw(user.fd, ErrorReplies::noSuchNick(temp));
				continue;
			}
			sendRaw(receiver->fd, msg);
		}
	}
	return true;
}