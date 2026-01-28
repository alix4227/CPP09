#include "PmergeMe.hpp"

bool checkNumbers(char* av)
{
	unsigned int num;
	int i = 0;
	std::stringstream check;
	check << av;
	check >> num;

	if (!av || av[0] == '\0')
		return (false);
	if (check.fail() || !check.eof())
		return (false);
	while (av[i])
	{
		if (!isdigit(av[i]))
			return (false);
		i++;
	}
	return (true);
}
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

bool comparePairs(Pair const& a, Pair const& b)
{
	return (a.greater <b.greater);
}

void	getJacobstalIndexes(std::vector<int>&index, int size)
{
	int i = 2;
	int k = 0;
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
}
std::vector<int> mergeInsertionSort(std::vector<int>&nb)
{
	if (nb.size() <= 1)
		return (nb);
	int orphan = 0;
	std::vector<Pair>A;
	std::vector<Pair>sorted;
	std::vector<int>smaller_chain;
	std::vector<int>greater_chain;
	std::vector<int>tmp;
	std::vector<int>index;
	size_t j = 0;
	size_t e = 0;
	bool hasOrphan = false;
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
	j = 0;
	while (j < A.size())
	{
		greater_chain.push_back(A[j].greater);
		smaller_chain.push_back(A[j].smaller);
		j++;
	}
	greater_chain = mergeInsertionSort(greater_chain);
	j = 0;
	while (j < greater_chain.size())
	{
		e = 0;
		while (e < A.size())
		{
			if (A[e].greater == greater_chain[j])
			{
				sorted.push_back(A[e]);
				A[e].greater = -1;
				break ;
			}
			e++;
		}
		j++;
	}
	A = sorted;
	greater_chain.clear();
	smaller_chain.clear();
	j = 0;
	while (j < A.size())
	{
		greater_chain.push_back(A[j].greater);
		smaller_chain.push_back(A[j].smaller);
		j++;
	}
	getJacobstalIndexes(index, smaller_chain.size() - 1);
	std::vector<int>main_chain(greater_chain);
	if (!smaller_chain.empty())
		main_chain.insert(main_chain.begin(), smaller_chain[0]);
	std::vector<bool> inserted(smaller_chain.size(), false);
	inserted[0] = true;
	j = 1;
	while (j < smaller_chain.size())
	{
		if (!inserted[index[j]])
		{
			int value = smaller_chain[index[j]];
			int greater_value = greater_chain[index[j]];
			std::vector<int>::iterator it = find(main_chain.begin(), main_chain.end(), greater_value);
			int pos_greater = distance(main_chain.begin(), it);
			int pos = findPosition(main_chain, value, pos_greater);
			main_chain.insert(main_chain.begin() + pos, value);
			inserted[index[j]] = true;
		}
		j++;
	}
	if (hasOrphan)
	{
		int pos = findPosition(main_chain, orphan, main_chain.size());
		main_chain.insert(main_chain.begin() + pos, orphan);
	}
	return (main_chain);
}