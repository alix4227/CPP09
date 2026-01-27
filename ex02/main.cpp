#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <deque>
#include <iostream>
#include <utility>
#include "PmergeMe.hpp"

int findPosition(std::vector<int>const& main_chain, int smaller, int pos_greater)
{
	int gauche = 0;
	int droite = pos_greater;

	while (gauche < droite)
	{
		int milieu = gauche + (droite - gauche) / 2;
		if (main_chain[milieu] < smaller)
			gauche = milieu + 1;
		else 
			droite = milieu;
	}
	return (gauche);
}

void sort_d(std::vector<int>& B, std::vector<int>&index)
{
	size_t i = 0;
	std::sort(B.begin(), B.end(), std::greater<int>());
	while (i < B.size())
	{
		index.push_back(B[i]);
		i++;
	}
}

void	getJacobstalIndexes(std::vector<int>&index, int size)
{
	int i = 2;
	int k = 0;
	// size_t e = 0;
	size_t j = 0;
	std::vector<int>A;
	std::vector<int>B;
	index.push_back(1);
	A.push_back(0);
	A.push_back(1);
	while (k < size)
	{
		A.push_back(A[i - 1] + (A[i - 2] * 2));
		k++;
		i++;
	}
	j = 2;
	while (j < A.size() && A[j] <= size)
	{
		i = A[j];
		while ((j + 1) < A.size() && i < A[j + 1] && i <= size)
		{
			B.push_back(i);
			i++;
		}
		sort_d(B, index);
		B.clear();
		j++;
	}
	// while (e < index.size())
	// {
	// 	std::cout << index[e] << std::endl;
	// 	e++;
	// }
}

bool comparePairs(Pair const& a, Pair const& b)
{
	return (a.greater <b.greater);
}

int	main(int ac, char**av)
{
	int i = 1;
	int orphan = 0;
	std::vector<Pair>A;
	std::vector<int>smaller_chain;
	std::vector<int>greater_chain;
	std::vector<int>tmp;
	std::vector<int>index;
	size_t j = 0;
	// size_t e = 0;
	std::vector<int>nb;
	bool hasOrphan = false;

	while (i < ac)
	{
		nb.push_back(std::atoi(av[i]));
		i++;
	}
	while (j < nb.size())
	{
		tmp.clear();
		if ((j + 1) != nb.size())
		{
			Pair pair;
			tmp.push_back(nb[j]);
			tmp.push_back(nb[j + 1]);
			std::sort(tmp.begin(), tmp.end());
			pair.smaller = tmp[0];
			pair.greater = tmp[1];
			A.push_back(pair);
			j += 2;
		}
		else
		{
			orphan = nb[j];
			hasOrphan = true;
			j++;
		}
	}
	std::sort(A.begin(), A.end(), comparePairs);
	j = 0;
	while (j < A.size())
	{
		greater_chain.push_back(A[j].greater);
		smaller_chain.push_back(A[j].smaller);
		j++;
	}
	getJacobstalIndexes(index, smaller_chain.size() - 1);
	std::vector<int>main_chain(greater_chain);
	// while (e < index.size())
	// {
	// 	std::cout << index[e] << std::endl;
	// 	e++;
	// }
	j = 0;
	while (j < smaller_chain.size())
	{
		int value = smaller_chain[index[j]];
		// std::cout << index[j] << std::endl;
		// std::cout << value << std::endl;
		int greater_value = greater_chain[index[j]];
		// std::cout << greater_value << std::endl;
		std::vector<int>::iterator it = find(main_chain.begin(), main_chain.end(), greater_value);
		int pos_greater = distance(main_chain.begin(), it);
		int pos = findPosition(main_chain, value, pos_greater);
		main_chain.insert(main_chain.begin() + pos, value);
		j++;
	}
	// main_chain.insert(main_chain.begin(), smaller_chain[index[0]]);
	// while (e < main_chain.size())
	// {
	// 	std::cout << main_chain[e] << std::endl;
	// 	e++;
	// }
	if (hasOrphan)
	{
		int pos = findPosition(main_chain, orphan, main_chain.size());
		main_chain.insert(main_chain.begin() + pos, orphan);
	}
	j = 0;
	while (j < main_chain.size())
	{
		std::cout << main_chain[j] << std::endl;
		j++;
	}
}