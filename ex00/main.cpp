#include "BitcoinExchange.hpp"
#include <exception>

bool isAllSpaces(std::string str)
{
	size_t i = 0;
	while (isspace(str[i]))
	{
		if (isspace(str[i]))
			i++;
	}
	if (i == str.size())
		return (true);
	return (false);
}

bool check_date(std::string str)
{ 
	if (str.length() != 10 || str[4] != '-' || str[7] != '-')
		return false;
	std::istringstream check(str);
	int year;
	check >> year;
	if (check.fail() || year < 0 || year < 2009)
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
	std::string day = str.substr(pos1 + 1);
	std::istringstream check2(day);
	int jour;
	check2 >> jour;
	if (check2.fail() || !check2.eof())
		return (false);
	int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (jour < 1 || jour > daysInMonth[mois - 1] || (year <= 2009 && mois == 01 && jour < 2))
		return (false);
    if ((year >= 2022 && mois >= 03 && jour > 29))
		return (false);
	return (true);
}

bool check_value(std::string str)
{
	if (str.empty() || isAllSpaces(str))
	{
		std::cout << "Error: Bad input(Allspaces)" << std::endl;
		return (false);
	}
	std::istringstream check(str);
	float value;
	check >> value;
	if (check.fail() || !check.eof())
	{
		std::cout << "Error: Bad input(Not a float)" << std::endl;
		return (false);
	}
	if (value < 0 || value > 50000)
	{
		if (value < 0)
			std::cout << "Error: Not a positive number" << std::endl;
		else
			std::cout << "Error: Too large a number" << std::endl;
		return (false);
	}	
	return(!check.fail() && check.eof());
}

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (0);
	}	

	Exchange rate;

	if (!rate.fillContainer())
	{
		std::cerr << "Error: could not open file (data.csv)" << std::endl;
		return (0);
	}
	std::string line;
	std::string date;
	std::string value;
	size_t pos;
	std::ifstream file(av[1]);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;	
		return (0);
	}
	if (file.peek() == EOF)
	{
		std::cerr << "Error: file empty." << std::endl;	
		return (0);
	}
	while (getline(file, line))
	{
		pos = line.find("date | value");
		if (pos != std::string::npos)
			continue ;
		if (line.empty())
			continue ;
		pos = line.find(" | ");
		date = line.substr(0, pos);
		if (!check_date(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (pos == std::string::npos)
		{
			std::cout << "Error: Wrong Format (date | value)" << std::endl;
			continue ;
		}
		value = line.substr(pos + 3);
		if (!check_value(value))
			continue ;
		std::istringstream check(value);
		float valeur;
		check >> valeur;
		rate.findRate(date, valeur);
	}
	return (0);
}