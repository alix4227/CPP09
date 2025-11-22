#include "BitcoinExchange.hpp"

Exchange::Exchange() {};

Exchange::~Exchange(){};

std::map<std::string, float>::iterator Exchange::begin() { return data.begin();}

std::map<std::string, float>::iterator Exchange::end() { return data.end();}

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

void Exchange::findDate(std::string date, float valeur)
{
	std::map<std::string, float>::iterator it;
	std::map<std::string, float>::iterator ite = end();

	for (it = begin(); it != ite; ++it)
	{
		if (date <= it->first)
		{
			_rate = valeur * data[it->first];
			std::cout << _rate << std::endl;
			return ;
		}
		else
		{
			_rate = valeur * data[it->first];
			std::cout << _rate << std::endl;
			return ;
		}
	}
}