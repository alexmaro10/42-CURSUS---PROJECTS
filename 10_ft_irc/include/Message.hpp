#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <vector>

class Server;

class Message {
public:
	Message(const std::string &raw);

	void parse();
	bool isValid() const;
	std::string getError() const;

	std::string format() const;
	void route(Server &server) const;

	const std::string &getCommand() const;
	const std::vector<std::string> &getParams() const;
	const std::string &getTrailing() const;
	bool hasTrailing() const;

	static Message construct(const std::string &command, const std::vector<std::string> &params, const std::string &trailing = "");
	static std::string replyTopic(const std::string &nick, const std::string &channel, const std::string &topicStr);

private:
	std::string rawMessage;
	std::string command;
	std::vector<std::string> params;
	std::string trailing;
	bool _hasTrailing;
	bool valid;
	std::string errorMsg;
};

#endif