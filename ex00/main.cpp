#include "BitcoinExchange.hpp"

int main (int ac, char **av)
{
	std::string line;
	std::map<std::string, double>occurences;
	if (ac < 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (0);
	}	
	std::ifstream file(av[1]);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;	
		return (0);
	}
	while (file >> line)
	{
		find()
		occurences[line] = 1;
	}
	std::cout << occurences["2022-03-29,47115.93"] << std::endl;	
	return (0);
}