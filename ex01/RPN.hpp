#ifndef RPN_HPP
#define RPN_HPP

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

class RPN: public std::stack<int>
{
	public:
	
	typedef typename std::stack<int>::container_type::iterator iterator;
	iterator begin();
	iterator end();
	int getResult(std::string temp);
	bool isNumbers(std::string temp);
	bool isOperator(std::string temp);
	int fillStack(std::string temp);
	void printResult(void);

	private:
	int _result;
	int _num;
};

#endif