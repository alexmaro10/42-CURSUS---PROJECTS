#include "ChannelBonus.hpp"
#include <iostream>

Channel::Channel()
	: _name(""), _inviteOnly(false), _topicRestricted(false), _hasKey(false), _hasUserLimit(false), _userLimit(0)
{
}

Channel::Channel(const std::string &name)
	: _name(name), _inviteOnly(false), _topicRestricted(false), _hasKey(false), _hasUserLimit(false), _userLimit(0)
{
}

const std::string &Channel::name() const
{
	return _name;
}

const std::set<int> &Channel::getMemberFds() const
{
	return _memberFds;
}

const std::set<int> &Channel::getOperators() const
{
	return _operators;
}

bool Channel::hasMember(int fd) const
{
	return _memberFds.find(fd) != _memberFds.end();
}

void Channel::addMember(int fd)
{
	_memberFds.insert(fd);
}

void Channel::removeMember(int fd)
{
	_memberFds.erase(fd);
	_operators.erase(fd);
	_invitedFds.erase(fd);
}

bool Channel::empty() const
{
	return _memberFds.empty();
}

void Channel::setTopic(const std::string &topic)
{
	_topic = topic;
}

std::string Channel::getTopic() const
{
	return _topic;
}

bool Channel::isInviteOnly() const
{
	return _inviteOnly;
}

void Channel::setInviteOnly(bool value)
{
	_inviteOnly = value;
}

bool Channel::isOperator(int fd) const
{
	return _operators.find(fd) != _operators.end();
}

bool Channel::isTopicRestricted() const
{
	return _topicRestricted;
}

void Channel::setTopicRestricted(bool value)
{
	_topicRestricted = value;
}

bool Channel::hasKey() const
{
	return _hasKey;
}

const std::string &Channel::getKey() const
{
	return _key;
}

void Channel::setKey(const std::string &key)
{
	_hasKey = true;
	_key = key;
}

void Channel::clearKey()
{
	_hasKey = false;
	_key.clear();
}

bool Channel::hasUserLimit() const
{
	return _hasUserLimit;
}

int Channel::getUserLimit() const
{
	return _userLimit;
}

void Channel::setUserLimit(int limit)
{
	_hasUserLimit = true;
	_userLimit = limit;
}

void Channel::clearUserLimit()
{
	_hasUserLimit = false;
	_userLimit = 0;
}

void Channel::addOperator(int fd)
{
	_operators.insert(fd);
}

void Channel::removeOperator(int fd)
{
	_operators.erase(fd);
}

bool Channel::isInvited(int fd) const
{
	return _invitedFds.find(fd) != _invitedFds.end();
}

void Channel::invite(int fd)
{
	_invitedFds.insert(fd);
}

void Channel::removeInvite(int fd)
{
	_invitedFds.erase(fd);
}
const std::set<int> &Channel::getMembers() const
{
	return _memberFds;
}

int Channel::nMembers() const
{
	int count;

	count = 0;
	for (std::set<int>::iterator it = _memberFds.begin(); it != _memberFds.end(); ++it)
	{
		count++;
	}
	return count;
}
