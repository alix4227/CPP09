#include "BitcoinExchange.hpp"

Exchange::Exchange(){};

Exchange::~Exchange(){};

void Exchange::fillContainer()
{
	std::string line;
	std::string date;
	std::string value;
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;	
		return ;
	}
	getline(file, line);
	while (getline(file, line))
	{
		if (line.empty())
			continue ;
		size_t pos = line.find(",");
		if (pos == std::string::npos)
		{
			std::cout << "Error: could not open file." << std::endl;
			return ;
		}
		date = line.substr(0, 10);
		data[date];
		
		value = line.substr(pos + 1);
		std::istringstream check(value);
		float valeur;
		check >> valeur;
		data[date] = valeur;
	}
}

void Exchange::findRate(std::string date, float valeur)
{
	if (date.empty())
		return ;
	std::map<std::string, float>::iterator it = data.upper_bound(date);
	--it;
	_rate = valeur * it->second;
	std::cout << date << " => " << "valeur "<< "= " << _rate << std::endl;
}