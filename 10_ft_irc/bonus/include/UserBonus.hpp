#ifndef USER_HPP_BONUS
#define USER_HPP_BONUS

#include <string>

class User
{
public:
	int fd;
	std::string ip;
	bool passOk;
	bool welcomed;
	std::string nickname;
	std::string username;
	std::string recvBuffer;
	int channelCount;

	User();
	User(int fd, const std::string &ip);
	User(const User &other);
	User &operator=(const User &other);
	~User();

	bool isOperator() const;
	void setOperator(bool value);
	std::string getNick() const;

private:
	bool _isOperator;
};

#endif
