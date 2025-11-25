#include "RPN.hpp"

int main (int ac , char **av)
{
	RPN rpn;
	if (ac != 2)
	{
		std::cout << "Error: No input" << std::endl;
		return (0);
	}
	std::istringstream s(av[1]);
	std::string temp;
	while (s >> temp)
	{
		if (rpn.isNumbers(temp))
		{
			if (!rpn.fillStack(temp))
				return (0);
		}
		else if (rpn.isOperator(temp))
		{
			if (!rpn.getResult(temp))
				return (0);
		}
		else 
		{
			std::cout << "Error: bad input" << std::endl;
			return (0);
		}
	}
	if (rpn.size() != 1)
	{
		std::cout << "Error: invalid expression" << std::endl;
		return (1);
	}
	rpn.printResult();
	return (0);
}