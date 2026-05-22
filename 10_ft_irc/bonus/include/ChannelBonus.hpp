#ifndef CHANNEL_HPP_BONUS
#define CHANNEL_HPP_BONUS

#include <set>
#include <string>

class Channel
{
public:
	Channel();
	explicit Channel(const std::string &name);

	const std::string &name() const;
	const std::set<int> &getMemberFds() const;
	const std::set<int> &getOperators() const;
	bool hasMember(int fd) const;
	int nMembers() const;
	void addMember(int fd);
	void removeMember(int fd);
	bool empty() const;

	std::string	getTopic() const;
	void		setTopic(const std::string &topic);

	bool		isInviteOnly() const;
	void		setInviteOnly(bool value);

	bool		isTopicRestricted() const;
	void		setTopicRestricted(bool value);

	bool		hasKey() const;
	const std::string &getKey() const;
	void		setKey(const std::string &key);
	void		clearKey();

	bool		hasUserLimit() const;
	int		getUserLimit() const;
	void		setUserLimit(int limit);
	void		clearUserLimit();

	bool		isOperator(int fd) const;
	void		addOperator(int fd);
	void		removeOperator(int fd);

	bool		isInvited(int fd) const;
	void		invite(int fd);
	void		removeInvite(int fd);

	const std::set<int> &getMembers() const;
		

private:
	std::string _name;
	std::set<int> _memberFds;
	std::string		_topic;
	bool			_inviteOnly;
	bool			_topicRestricted;
	bool			_hasKey;
	std::string		_key;
	bool			_hasUserLimit;
	int				_userLimit;
	std::set<int>	_operators;
	std::set<int>	_invitedFds;
};

#endif
