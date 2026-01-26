#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <deque>
#include <iostream>
#include <utility>
#include "PmergeMe.hpp"

int findPosition(vector<int>const& chaine, int valeurPetite, int positionValeurGrande)
{
	int gauche = 0;
	int droite = positionValeurGrande;

	while (gauche < droite)
	{
		int milieu = gauche + (droite - gauche) / 2;
		if (chaine[milieu] < valeurPetite)
			gauche = milieu + 1;
		else 
			droite = milieu;
	}
	return (gauche);
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
	std::vector<int>B;
	std::vector<int>main_chain;
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
		main_chain.push_back(A[j].greater);
		B.push_back(A[j].smaller);
		j++;
	}
	// main_chain.insert(main_chain.begin(), B[0]);
	// B.insert(B.begin(), B[0]);
	j = 0;
	while (j < main_chain.size())
	{
		std::cout << main_chain[j] << std::endl;
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