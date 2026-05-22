#include "ErrorReplies.hpp"

std::string ErrorReplies::notRegistered()
{
	return ":ft_irc 451 * :You have not registered\r\n";
}

std::string ErrorReplies::needMoreParams(const std::string &command)
{
	return ":ft_irc 461 * " + command + " :Not enough parameters\r\n";
}

std::string ErrorReplies::noNicknameGiven()
{
	return ":ft_irc 431 * :No nickname given\r\n";
}

std::string ErrorReplies::nicknameInUse(const std::string &nick)
{
	return ":ft_irc 433 * " + nick + " :Nickname is already in use\r\n";
}

std::string ErrorReplies::passwordIncorrect()
{
	return ":ft_irc 464 * :Password incorrect\r\n";
}

std::string ErrorReplies::noTextToSend()
{
	return ":ft_irc 412 * :No text to send\r\n";
}

std::string ErrorReplies::noSuchNick(const std::string &target)
{
	return ":ft_irc 401 " + target + " :No such nick\r\n";
}

std::string ErrorReplies::noSuchChannel(const std::string &channel)
{
	return ":ft_irc 403 * " + channel + " :No such channel\r\n";
}

std::string ErrorReplies::noTopic(const std::string &nick, const std::string &channel)
{
	return ":ft_irc 331 " + nick + " " + channel + " :No topic is set\r\n";
}

std::string ErrorReplies::userNotOnChannel(const std::string &user, const std::string &channel)
{
	return ":ft_irc 441 * " + user + " " + channel + " :They aren't on that channel\r\n";
}

std::string ErrorReplies::notOnChannel(const std::string &nick, const std::string &channel)
{
	return ":ft_irc 442 " + nick + " " + channel + " :You're not on that channel\r\n";
}

std::string ErrorReplies::userAlreadyOnChannel(const std::string &user, const std::string &channel)
{
	return ":ft_irc 443 * " + user + " " + channel + " :is already on channel\r\n";
}

std::string ErrorReplies::userNotOperator()
{
	return ":ft_irc 481 * :Permission Denied- You're not an IRC operator\r\n";
}

std::string ErrorReplies::chanopPrivsNeeded(const std::string &nick, const std::string &channel)
{
	return ":ft_irc 482 " + nick + " " + channel + " :You're not channel operator\r\n";
}

std::string ErrorReplies::userNotInChannel(const std::string &nick, const std::string &channel)
{
	return ":ft_irc 441 " + nick + " " + channel + " :They aren't on that channel\r\n";
}

std::string ErrorReplies::inviteOnlyChan(const std::string &nick, const std::string &channel)
{
	return ":ft_irc 473 " + nick + " " + channel + " :Cannot join channel (+i)\r\n";
}

std::string ErrorReplies::badChannelKey(const std::string &nick, const std::string &channel)
{
	return ":ft_irc 475 " + nick + " " + channel + " :Cannot join channel (+k)\r\n";
}

std::string ErrorReplies::channelIsFull(const std::string &nick, const std::string &channel)
{
	return ":ft_irc 471 " + nick + " " + channel + " :Cannot join channel (+l)\r\n";
}

std::string ErrorReplies::unknownCommand(const std::string &command)
{
	return ":ft_irc 421 " + command + " :Unknown command\r\n";
}

std::string ErrorReplies::noPass()
{
	return ":ft_irc 464 * :No pass given\r\n";
}
