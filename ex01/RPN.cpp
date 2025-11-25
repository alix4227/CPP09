#include "RPN.hpp"

typename std::stack<int>::container_type::iterator RPN::begin()
{
	return (this->c.begin());
}
typename std::stack<int>::container_type::iterator RPN::end()
{
	
	return (this->c.end());
}
bool RPN::isNumbers(std::string temp)
{
	std::istringstream check(temp);
	int num;
	check >> num;
	if (check.fail() || !check.eof())
		return (false);
	return (true);
}
int RPN::fillStack(std::string temp)
{
	_num = atoi(temp.c_str());
	if (_num > 9)
	{
		std::cout << "Error: number out of range" << std::endl;
		return (0);
	}
	this->push(_num);
	return (1);
}

bool RPN::isOperator(std::string temp)
{
	std::string operators = "+-/*";
	if (!this->empty() && operators.find(temp[0]) != std::string::npos)
		return (true);
	return (false);
}
int RPN::getResult(std::string temp)
{
	if (this->size() < 2)
	{
		std::cout << "Error: Not enough operandes" << std::endl;
		return (0);
	}
	int droite = this->top();
	this->pop();
	int gauche = this->top();
	this->pop();
	if (temp[0] == '+')
		_result = gauche + droite;
	if (temp[0] == '-')
		_result = gauche - droite;
	if (temp[0] == '*')
		_result = gauche * droite;
	if (temp[0] == '/')
		_result = gauche / droite;
	this->push(_result);
	return (1);
}
void RPN::printResult(void)
{
	RPN::iterator it = begin();
	RPN::iterator ite = end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}