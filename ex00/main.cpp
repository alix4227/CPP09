#include "BitcoinExchange.hpp"

int main (int ac, char **av)
{
	std::string line;
	std::string date;
	std::string value;
	// std::map<std::string, double>occurences;
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
		size_t pos = line.find(",");
		date = line.substr(0, pos);
		value = line.substr(pos + 1);
		std::cout <<date << std::endl;
		std::cout <<value << std::endl;
	}
	return (0);
}