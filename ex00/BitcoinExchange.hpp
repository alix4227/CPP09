#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <sstream>

class Exchange
{
	public:
	Exchange();
	~Exchange();
	void fillContainer();
	void findRate(std::string date, float valeur);

	private:
	std::map<std::string, float>data;
	float _rate;
};
#endif