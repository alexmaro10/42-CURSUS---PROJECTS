#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return (*this);
}

RPN::~RPN() {}

bool isOperator(const std::string &token)
{
	if (token.size() != 1)
		return (false);
	char c = token[0];
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int applyOperator(int a, int b, const std::string &op)
{
	if (op == "+")
		return (a + b);
	if (op == "-")
		return (a - b);
	if (op == "*")
		return (a * b);
	if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Error: division by zero");
		return (a / b);
	}
	throw std::runtime_error("Error: unknown operator");
}

int RPN::evaluate(const std::string &expression) const
{
	std::stack<int>	numbers;
	std::istringstream	iss(expression);
	std::string			token;

	while (iss >> token)
	{
		if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
		{
			numbers.push(token[0] - '0');
		}
		else if (isOperator(token))
		{
			if (numbers.size() < 2)
				throw std::runtime_error("Error: not enough operands");

			int b = numbers.top(); numbers.pop();
			int a = numbers.top(); numbers.pop();

			numbers.push(applyOperator(a, b, token));
		}
		else
		{
			throw std::runtime_error("Error: invalid token \"" + token + "\"");
		}
	}

	if (numbers.size() != 1)
		throw std::runtime_error("Error: malformed expression");

	return (numbers.top());
}
