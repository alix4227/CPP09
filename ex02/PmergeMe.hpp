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

bool checkNumbers(char* av);
int findPosition_deque(std::deque<int>const& main_chain, int smaller, int pos_greater);
void sort_d_deque(std::deque<int>& B, std::deque<int>&index);
bool comparePairs_deque(Pair const& a, Pair const& b);
void	getJacobstalIndexes_deque(std::deque<int>&index, int size);
std::deque<int> mergeInsertionSort_deque(std::deque<int>&nb);

int findPosition(std::vector<int>const& main_chain, int smaller, int pos_greater);
void sort_d(std::vector<int>& B, std::vector<int>&index);
bool comparePairs(Pair const& a, Pair const& b);
void	getJacobstalIndexes(std::vector<int>&index, int size);
std::vector<int> mergeInsertionSort(std::vector<int>&nb);

#endif