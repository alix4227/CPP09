#include "BitcoinExchange.hpp"

Exchange::Exchange(){};

Exchange::~Exchange(){};

bool Exchange::fillContainer()
{
	std::string line;
	std::string date;
	std::string value;
	std::ifstream file("data.csv");
	if (!file.is_open())
		return (false);
	getline(file, line);
	while (getline(file, line))
	{
		if (line.empty())
			continue ;
		size_t pos = line.find(",");
		if (pos == std::string::npos)
			return (false);
		date = line.substr(0, 10);
		if (!check_date(date))
			return (false);
		data[date];

		value = line.substr(pos + 1);
		if (!check_value_data(value))
			return (false);
		std::istringstream check(value);
		float valeur;
		check >> valeur;
		data[date] = valeur;
	}
	return (true);
}

void Exchange::findRate(std::string date, float valeur)
{
	if (date.empty())
		return ;
	std::map<std::string, float>::iterator it = data.upper_bound(date);
	if (it != data.begin())
		--it;
	_rate = valeur * it->second;
	std::cout << date << " => " << valeur << " = " << _rate << std::endl;
}

bool check_value_data(std::string str)
{
	if (str.empty() || isAllSpaces(str))
	
		return (false);
	std::istringstream check(str);
	float value;
	check >> value;
	if (check.fail() || !check.eof())
		return (false);
	if (value < 0 || value > 5000000)
		return (false);
	return(!check.fail() && check.eof());
}