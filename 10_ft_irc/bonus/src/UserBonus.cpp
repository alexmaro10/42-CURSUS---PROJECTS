#include "UserBonus.hpp"


User::User()
	: fd(-1), passOk(false), welcomed(false), channelCount(0), _isOperator(false)
{
}


User::User(int userFd, const std::string &userIp)
	: fd(userFd), ip(userIp), passOk(false), welcomed(false), channelCount(0), _isOperator(false)
{
}


User::User(const User &other)
	: fd(other.fd),
	  ip(other.ip),
	  passOk(other.passOk),
	  welcomed(other.welcomed),
	  nickname(other.nickname),
	  username(other.username),
	  recvBuffer(other.recvBuffer),
	  channelCount(other.channelCount),
	  _isOperator(other._isOperator)
{
}


User &User::operator=(const User &other)
{
	if (this != &other)
	{
		fd = other.fd;
		ip = other.ip;
		passOk = other.passOk;
		welcomed = other.welcomed;
		nickname = other.nickname;
		username = other.username;
		recvBuffer = other.recvBuffer;
		channelCount = other.channelCount;
		_isOperator = other._isOperator;
	}
	return *this;
}


User::~User()
{
}

bool User::isOperator() const {
	return _isOperator;
}

void User::setOperator(bool value) {
	_isOperator = value;
}

std::string User::getNick() const
{
	return nickname;
}