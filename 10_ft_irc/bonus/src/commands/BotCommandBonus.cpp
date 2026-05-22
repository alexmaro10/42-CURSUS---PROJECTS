#include "CommandHandlerBonus.hpp"
#include "ErrorRepliesBonus.hpp"
#include "UserManagerBonus.hpp"
#include "ChannelManagerBonus.hpp"

#include <set>
#include <sstream>


bool CommandHandler::handleBot(User &user, std::istringstream &iss) const
{
	std::string question;
	std::getline(iss, question);

	if (question.empty())
	{
		sendRaw(user.fd, ErrorReplies::needMoreParams("BOT"));
		return true;
	}

	std::string response;

	if (question == "hola")
		response = "¡Hola, caracola!";
	else if (question == "has dormido?" || question == "Has dormido?")
		response = "Dormir es para débiles.";
	else if (question == "me aburro")
		response = "Pues échate en agua";
	else
		response = "Habla claro, que no te entiendo";

	
	sendRaw(user.fd,
		":bot!bot@ft_irc PRIVMSG "
		+ user.nickname + " :" + response);
	return true;
}