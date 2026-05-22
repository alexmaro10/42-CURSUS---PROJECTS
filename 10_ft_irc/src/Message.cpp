#include "CommandHandler.hpp"
#include "Message.hpp"
#include "Server.hpp"
#include <sstream>
#include <iostream>

Message::Message(const std::string &raw) : rawMessage(raw), _hasTrailing(false), valid(false) {
		parse();
}

void Message::parse() {
		std::istringstream iss(rawMessage);
		std::string token;
		valid = true;
		errorMsg.clear();
		command.clear();
		params.clear();
		trailing.clear();
		_hasTrailing = false;

		if (!(iss >> token)) {
				valid = false;
				errorMsg = "Missing input";
				return;
		}
		if (CommandHandler::isKnownCommand(token)) {
			command = token;
			while (iss >> token) {
					if (!_hasTrailing && token[0] == ':') {
							_hasTrailing = true;
							trailing = token.substr(1);
							std::string rest;
							std::getline(iss, rest);
							if (!rest.empty()) trailing += rest;
					} else if (!_hasTrailing) {
							params.push_back(token);
					} else {
							trailing += " " + token;
					}
			
			}
		} else {
				command.clear();
				params.clear();
				trailing.clear();
				trailing = rawMessage;
		}
}

bool Message::isValid() const {
		return valid;
}

std::string Message::getError() const {
		return errorMsg;
}

std::string Message::format() const {
		std::ostringstream oss;
		oss << command;
		for (size_t i = 0; i < params.size(); ++i) {
				oss << " " << params[i];
		}
		if (!trailing.empty()) oss << " :" << trailing;
		return oss.str();
}

void Message::route(Server &server) const {
		(void)server;
}

const std::string &Message::getCommand() const { return command; }
const std::vector<std::string> &Message::getParams() const { return params; }
const std::string &Message::getTrailing() const { return trailing; }

bool Message::hasTrailing() const {
		return _hasTrailing;
}

Message Message::construct(const std::string &command, const std::vector<std::string> &params, const std::string &trailing) {
		std::ostringstream oss;
		oss << command;
		for (size_t i = 0; i < params.size(); ++i) {
				oss << " " << params[i];
		}
		if (!trailing.empty()) oss << " :" << trailing;
		return Message(oss.str());
}

std::string Message::replyTopic(const std::string &nick, const std::string &channel, const std::string &topicStr) {
		return ":ft_irc 332 " + nick + " " + channel + " :" + topicStr + "\r\n";
}
