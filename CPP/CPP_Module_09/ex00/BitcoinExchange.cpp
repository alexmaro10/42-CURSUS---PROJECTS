#include "BitcoinExchange.hpp"

/* ------------------------------------------------------------------ */
/*                      Forma canónica ortodoxa                       */
/* ------------------------------------------------------------------ */

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database) {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_database = other._database;
	return (*this);
}

std::string trim(const std::string &str)
{
	size_t start = str.find_first_not_of(" \t");
	if (start == std::string::npos)
		return ("");
	size_t end = str.find_last_not_of(" \t");
	return (str.substr(start, end - start + 1));
}

bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int daysInMonth(int month, int year)
{
	static const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2 && isLeapYear(year))
		return (29);
	return (days[month - 1]);
}

bool parseDate(const std::string &date, int &y, int &m, int &d)
{
	if (date.size() != 10)
		return (false);
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				return (false);
		}
		else if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}
	y = std::atoi(date.substr(0, 4).c_str());
	m = std::atoi(date.substr(5, 2).c_str());
	d = std::atoi(date.substr(8, 2).c_str());
	return (true);
}

bool isValidDate(const std::string &date)
{
	int y, m, d;

	if (!parseDate(date, y, m, d))
		return (false);
	if (y < 1900 || y > 2100)
		return (false);
	if (m < 1 || m > 12)
		return (false);
	if (d < 1 || d > daysInMonth(m, y))
		return (false);
	return (true);
}

int checkValue(const std::string &valueStr, double &value)
{
	if (valueStr.empty())
		return (1);

	const char *cstr = valueStr.c_str();
	char *endptr = NULL;

	value = std::strtod(cstr, &endptr);
	if (endptr == cstr || *endptr != '\0')
		return (1);
	if (value < 0)
		return (2);
	if (value > 1000)
		return (3);
	return (0);
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open database file \"" + filename + "\"");

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line))
	{
		line = trim(line);
		if (line.empty())
			continue;
		if (firstLine)
		{
			firstLine = false;
			continue;
		}

		size_t sep = line.find(',');
		if (sep == std::string::npos)
			continue;

		std::string date = trim(line.substr(0, sep));
		std::string valueStr = trim(line.substr(sep + 1));

		if (!isValidDate(date))
			continue;

		char *endptr = NULL;
		double value = std::strtod(valueStr.c_str(), &endptr);
		if (endptr == valueStr.c_str() || *endptr != '\0')
			continue;

		_database[date] = value;
	}

	if (_database.empty())
		throw std::runtime_error("database \"" + filename + "\" is empty or invalid");
}

static long dateToDays(const std::string &date)
{
	int y, m, d;

	parseDate(date, y, m, d);
	if (m <= 2)
		y--;
	long era = y / 400;                       // y >= 1900, siempre positivo
	long yoe = y - era * 400;
	long doy = (153 * (m + (m > 2 ? -3 : 9)) + 2) / 5 + d - 1;
	long doe = yoe * 365 + yoe / 4 - yoe / 100 + doy;
	return (era * 146097 + doe);
}

bool BitcoinExchange::getRate(const std::string &date, double &rate) const
{
	if (_database.empty())
		return (false);

	std::map<std::string, double>::const_iterator it = _database.lower_bound(date);

	// Fecha exacta
	if (it != _database.end() && it->first == date)
	{
		rate = it->second;
		return (true);
	}

	// Posterior a todas las fechas de la base de datos -> la última
	if (it == _database.end())
	{
		--it;
		rate = it->second;
		return (true);
	}

	// Anterior a todas las fechas de la base de datos -> la primera
	if (it == _database.begin())
	{
		rate = it->second;
		return (true);
	}

	// Está entre dos fechas: comparar distancias
	std::map<std::string, double>::const_iterator prev = it;
	--prev;

	long target = dateToDays(date);
	long diffPrev = target - dateToDays(prev->first);
	long diffNext = dateToDays(it->first) - target;

	// En caso de empate se prefiere la fecha anterior
	rate = (diffPrev <= diffNext) ? prev->second : it->second;
	return (true);
}

void BitcoinExchange::processInputFile(const std::string &filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line))
	{
		line = trim(line);
		if (line.empty())
			continue;

		if (firstLine)
		{
			firstLine = false;
			if (line.find("date") != std::string::npos
				&& line.find("value") != std::string::npos)
				continue;
		}

		size_t sep = line.find('|');
		if (sep == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string datePart = trim(line.substr(0, sep));
		std::string valuePart = trim(line.substr(sep + 1));

		if (!isValidDate(datePart))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		double value = 0;
		int code = checkValue(valuePart, value);

		if (code == 1)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		else if (code == 2)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		else if (code == 3)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		double rate = 0;
		if (!getRate(datePart, rate))
		{
			std::cout << "Error: no data available for date " << datePart << std::endl;
			continue;
		}

		std::cout << datePart << " => " << value << " = " << (value * rate) << std::endl;
	}
}
