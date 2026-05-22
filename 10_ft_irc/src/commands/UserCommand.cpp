#include "CommandHandler.hpp"
#include "ErrorReplies.hpp"

#include <sstream>

bool CommandHandler::handleUser(User &user, std::istringstream &iss) const
{
	if (!user.passOk)
	{
		sendRaw(user.fd, ErrorReplies::noPass());
		return true;
	}
	std::string username, hostname, servername, realname;
	iss >> username >> hostname >> servername;

	std::getline(iss, realname);
	if (!realname.empty() && realname[0] == ' ')
		realname.erase(0, 1);

	if (username.empty() || hostname.empty() || servername.empty() || realname.empty() || realname[0] != ':') {
		sendRaw(user.fd, ErrorReplies::needMoreParams("USER"));
		return true;
	}
	user.username = username;
	sendNotice(user.fd, user.nickname.empty() ? "*" : user.nickname, "Username set to " + user.username);
	maybeSendWelcome(user);
	return true;
}