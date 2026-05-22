#include "CommandHandler.hpp"
#include "ErrorReplies.hpp"

#include <sstream>

bool CommandHandler::handleNick(User &user, UserManager &users, std::istringstream &iss) const
{
	if (!user.passOk)
	{
		sendRaw(user.fd, ErrorReplies::noPass());
		return true;
	}
	std::string nick;
	iss >> nick;
	if (nick.empty())
	{
		sendRaw(user.fd, ErrorReplies::noNicknameGiven());
		return true;
	}
	if (users.isNicknameInUse(nick, user.fd))
	{
		sendRaw(user.fd, ErrorReplies::nicknameInUse(nick));
		return true;
	}
	user.nickname = nick;
	sendNotice(user.fd, user.nickname, "Nickname set to " + user.nickname);
	maybeSendWelcome(user);
	return true;
}
