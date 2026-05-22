#ifndef CHANNELMANAGER_HPP_BONUS
#define CHANNELMANAGER_HPP_BONUS

#include "ChannelBonus.hpp"

#include <map>
#include <string>

class ChannelManager
{
public:
	bool has(const std::string &name) const;
	Channel *get(const std::string &name);
	const Channel *get(const std::string &name) const;
	Channel &getOrCreate(const std::string &name);
	void removeIfEmpty(const std::string &name);
	const std::map<std::string, Channel> &getChannels() const;
private:
	std::map<std::string, Channel> _channels;
};

#endif
