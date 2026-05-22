#ifndef USERMANAGER_HPP_BONUS
#define USERMANAGER_HPP_BONUS

#include "UserBonus.hpp"

#include <map>
#include <string>

class UserManager
{
public:
	std::map<int, User> &all();
	const std::map<int, User> &all() const;

	void add(int fd, const std::string &ip);
	void remove(int fd);

	bool has(int fd) const;
	User *get(int fd);
	const User *get(int fd) const;

	bool isNicknameInUse(const std::string &nick, int exceptFd) const;

	User *getUserByNick(const std::string &nick);
	const User *getUserByNick(const std::string &nick) const;

private:
	std::map<int, User> _users;
};

#endif