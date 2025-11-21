#include "BitcoinExchange.hpp"
#include <exception>

bool check_date(std::string str)
{ 
	if (str.length() != 10 || str[4] != '-' || str[7] != '-')
        return false;
	std::istringstream check(str);
	int year;
	check >> year;
	if (check.fail() || year < 0)
		return (false);

	size_t pos = str.find("-");
	std::string month = str.substr(pos + 1, 2);
	std::istringstream check1(month);
	int mois;
	check1 >> mois;
	if (check1.fail() || !check1.eof())
		return (false);
	if (mois < 1 || mois > 12)
		return (false);

	size_t pos1 = str.find_last_of("-");
	std::string day = str.substr(pos1 + 1, 2);
	std::istringstream check2(day);
	int jour;
	check2 >> jour;
	if (check2.fail() || !check2.eof())
		return (false);
	if (jour < 1 || jour > 31)
		return (false);
	return (true);
}
bool check_value(std::string str)
{
	std::istringstream check(str);
	float value;
	check >> value;
	if (value < 0 || value > 1000)
			return (false);
	return(!check.fail() && check.eof());
}
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
		size_t pos = line.find("|");
		if (pos == std::string::npos)
			std::cout << "Error: could not open file." << std::endl;
		date = line.substr(0, pos);
		if (!check_date(date))
			std::cout << "Error: could not open file." << std::endl;
		value = line.substr(pos + 1);
		if (!check_value(value))
			std::cout << "Error: could not open file." << std::endl;
	}
	return (0);
}