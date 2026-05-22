#ifndef ERRORREPLIES_HPP_BONUS
#define ERRORREPLIES_HPP_BONUS

#include <string>

class ErrorReplies
{
public:
	static std::string notRegistered();
	static std::string needMoreParams(const std::string &command);
	static std::string noNicknameGiven();
	static std::string nicknameInUse(const std::string &nick);
	static std::string passwordIncorrect();
	static std::string noTextToSend();
	static std::string noSuchNick(const std::string &target);
	static std::string noSuchChannel(const std::string &channel);
	static std::string noTopic(const std::string &nick, const std::string &channel);
	static std::string notOnChannel(const std::string &nick, const std::string &channel);
	static std::string userAlreadyOnChannel(const std::string &user, const std::string &channel);
	static std::string userNotOperator();
	static std::string unknownCommand(const std::string &command);
	static std::string userNotOnChannel(const std::string &user, const std::string &channel);
	static std::string chanopPrivsNeeded(const std::string &nick, const std::string &channel);
	static std::string userNotInChannel(const std::string &nick, const std::string &channel);
	static std::string inviteOnlyChan(const std::string &nick, const std::string &channel);
	static std::string badChannelKey(const std::string &nick, const std::string &channel);
	static std::string channelIsFull(const std::string &nick, const std::string &channel);
	static std::string noPass();
};

#endif
