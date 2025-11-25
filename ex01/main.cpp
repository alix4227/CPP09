#include "RPN.hpp"

bool isNumbers(std::string temp)
{
	std::istringstream check(temp);
	int num;
	check >> num;
	if (check.fail())
		return (false);
	return (true);
}
bool isOutOfRange(int i)
{
    if ( i < 0 || i > 9)
		return (true);
	return (false);
}
int main (int ac , char **av)
{
	size_t i = 0;
	RPN<int>rpn;
	int result;
	int num;
	if (ac != 2)
		return (0);
	std::istringstream s(av[1]);
	std::string temp;
	while (s >> temp)
	{
		if (isNumbers(temp))
		{
			num = atoi(temp.c_str());
			if (num > 9)
			{
				std::cout << "Error: number out of range" << std::endl;
				return (0);
			}
			rpn.push(num);
		}
		else if (temp[0] == '+' && !rpn.empty())
		{
			int droite = rpn.top();
			rpn.pop();
			result = rpn.top() + droite;
			rpn.pop();
			rpn.push(result);
		}
		else if (temp[0] == '-' && !rpn.empty())
		{
			int droite = rpn.top();
			rpn.pop();
			result = rpn.top() - droite;
			rpn.pop();
			rpn.push(result);
		}	
		else if (temp[0] == '/' && !rpn.empty())
		{
			int droite = rpn.top();
			rpn.pop();
			result =  rpn.top() / droite;
			rpn.pop();
			rpn.push(result);
		}
		else if (temp[0] == '*' && !rpn.empty())
		{
			int droite = rpn.top();
			rpn.pop();
			result =  rpn.top() * droite;
			rpn.pop();
			rpn.push(result);
		}
		else 
		{
			std::cout << "Error: bad input" << std::endl;
			return (0);
		}
		i++;
	}
	while (!rpn.empty())
	{
		rpn.pop();
	}
	rpn.push(result);
	RPN<int>::iterator it = rpn.begin();
	RPN<int>::iterator ite = rpn.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return (0);
}