#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <cstdlib>
# include <cctype>
# include <stdexcept>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_database;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	loadDatabase(const std::string &filename);
		void	processInputFile(const std::string &filename) const;
		bool	getRate(const std::string &date, double &rate) const;


};

#endif
