#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <deque>
#include <iostream>
#include <utility>
#include "PmergeMe.hpp"

// int findPosition(vector<int>const& chaine, int valeurPetite, int positionValeurGrande)
// {
// 	int gauche = 0;
// 	int droite = positionValeurGrande;

// 	while (gauche < droite)
// 	{
// 		int milieu = gauche + (droite - gauche) / 2;
// 		if (chaine[milieu] < valeurPetite)
// 			gauche = milieu + 1;
// 		else 
// 			droite = milieu;
// 	}
// 	return (gauche);
// }

bool comparePairs(Pair const& a, Pair const& b)
{
	return (a.greater <b.greater);
}

int	main(int ac, char**av)
{
	int i = 1;
	int orphan = 0;
	std::vector<Pair>A;
	std::vector<Pair>main_chain;
	std::vector<int>smaller_chain;
	std::vector<int>greater_chain;
	std::vector<int>tmp;
	size_t j = 0;
	std::vector<int>nb;

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
	j = 0;
	while (j < smaller_chain.size())
	{
		int value = smaller_chain[index[j]];
		// chercher position de l'autre element de la paire dans main_chain(greater_chain[index[j]])
		int pos = findPosition(main_chain, value, pos_greater);
		main_chain.insert(main_chain.begin() + pos, value);
		j++;
	}
	j = 0;
	while (j < greater_chain.size())
	{
		std::cout << greater_chain[j] << std::endl;
		j++;
	}
	j = 0;
	while (j < B.size())
	{
		std::cout << B[j] << std::endl;
		j++;
	}
	std::cout << orphan << std::endl;
}