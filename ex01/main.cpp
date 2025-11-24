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
				rpn.push(atoi(temp.c_str()));
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
	// if (!temp.empty())
	// 	rpn.push_back(atoi(temp.c_str()));
	// bool checkNumbersRange = (std::find_if(rpn.begin(), rpn.end(), isOutOfRange) == rpn.end());
	// if (!checkNumbersRange)
	// {
	// 	std::cout << "Error: wrong numbers" << std::endl;
	// 	return (0);
	// }

}