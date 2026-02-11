#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <deque>
#include <iostream>
#include <utility>
#include <ctime>

struct Pair
{
	int smaller;
	int greater;
};

class PmergeMe
{

	public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe const& src);
	PmergeMe& operator=(PmergeMe const& src);

	bool checkNumbers(char* av);
	std::deque<int> mergeInsertionSort_deque(std::deque<int>&nb);
	std::vector<int> mergeInsertionSort(std::vector<int>&nb);

	int		findPosition_deque(std::deque<int>const& main_chain, int smaller, int pos_greater);
	void	getJacobstalIndexes_deque(std::deque<int>&index, int size);

	int		findPosition(std::vector<int>const& main_chain, int smaller, int pos_greater);
	void	getJacobstalIndexes(std::vector<int>&index, int size);
};


template <typename T>
void printBefore(T const& v)
{
	size_t j = 0;
	std::cout << "Before:  ";
	while (j < v.size())
	{
		std::cout << v[j] << " ";
		j++;
	}
	std::cout << std::endl;
	std::cout << std::endl;

}
template <typename T>
void printAfter(T const& v, int ac)
{(void)ac;
	size_t j = 0;
	std::cout << "After:   ";
	while (j < v.size())
	{
		std::cout << v[j] << " ";
		j++;
	}
	std::cout << std::endl;
	std::cout << std::endl;;
}
// template<typename Container>
// bool isSorted(const Container& c) {
//     for (size_t i = 1; i < c.size(); ++i) {
//         if (c[i] < c[i - 1])
//             return false;
//     }
//     return true;
// }
#endif