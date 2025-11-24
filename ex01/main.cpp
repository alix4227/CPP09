#include "RPN.hpp"
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
	std::string numbers = av[1];
	std::string temp;
	while (i < numbers.size())
	{
		if (isdigit(numbers[i]))
			temp += numbers[i];
		else if (isspace(numbers[i]))
		{
			if (!temp.empty())
			{
				num = atoi(temp.c_str());
				if (num > 9)
				{
					std::cout << "Error: number out of range" << std::endl;
					return (0);
				}
				rpn.push(num);
				temp = "";
			}
		}
		else if (numbers[i] == '+')
		{
			int droite = rpn.top();
			rpn.pop();
			result = rpn.top() + droite;
			rpn.pop();
			rpn.push(result);
		}
		else if (numbers[i] == '-')
		{
			int droite = rpn.top();
			rpn.pop();
			result = rpn.top() - droite;
			rpn.pop();
			rpn.push(result);
		}	
		else if (numbers[i] == '/')
		{
			int droite = rpn.top();
			rpn.pop();
			result =  rpn.top() / droite;
			rpn.pop();
			rpn.push(result);
		}
		else if (numbers[i] == '*')
		{
			int droite = rpn.top();
			rpn.pop();
			result =  rpn.top() * droite;
			rpn.pop();
			rpn.push(result);
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