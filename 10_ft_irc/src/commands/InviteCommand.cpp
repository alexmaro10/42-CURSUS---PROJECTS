
#include "CommandHandler.hpp"
#include "ErrorReplies.hpp"
#include "ChannelManager.hpp"

bool CommandHandler::handleInvite(User &user, UserManager &users, std::istringstream &iss) const {
	std::string targetNick, channelName;
	iss >> targetNick >> channelName;
	if (targetNick.empty() || channelName.empty()) {
		sendRaw(user.fd, ErrorReplies::needMoreParams("INVITE"));
		return true;
	}

	Channel *ch = _channels.get(channelName);
	if (!ch)
	{
		sendRaw(user.fd, ErrorReplies::noSuchChannel(channelName));
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

	User *targetUser = NULL;
	for (std::map<int, User>::iterator it = users.all().begin(); it != users.all().end(); ++it) {
		if (it->second.nickname == targetNick) {
			targetUser = &it->second;
			break;
		}
	}
	if (!targetUser) {
		sendRaw(user.fd, ErrorReplies::noSuchNick(targetNick));
		return true;
	}
	if (!ch->hasMember(targetUser->fd))
		ch->invite(targetUser->fd);

	std::string msg = ":" + user.nickname + "!" + user.username + "@server INVITE " + targetNick + " :" + channelName;
	sendRaw(targetUser->fd, msg);
	sendRaw(user.fd, ":ft_irc 341 " + user.nickname + " " + targetNick + " " + channelName + " :Invite sent");
	sendNotice(user.fd, user.nickname, "Invited " + targetNick + " to " + channelName);
	sendNotice(targetUser->fd, targetNick, "You have been invited to " + channelName + " by " + user.nickname);
	return true;
}
