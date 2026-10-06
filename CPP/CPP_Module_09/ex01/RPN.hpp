#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>
# include <string>
# include <stdexcept>
# include <cctype>

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int	evaluate(const std::string &expression) const;
};

#endif
