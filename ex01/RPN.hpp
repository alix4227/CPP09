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

template <typename T>
class RPN: public std::stack<T>
{
	public:
	
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();

	private:
	
	
};

template <typename T>
typename std::stack<T>::container_type::iterator RPN<T>::begin()
{
	return (this->c.begin());
}
template <typename T>
typename std::stack<T>::container_type::iterator RPN<T>::end()
{
	
	return (this->c.end());
}
#endif