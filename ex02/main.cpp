#include "PmergeMe.hpp"


int	main(int ac, char**av)
{
	int i = 1;
	size_t j = 0;
	
	std::cout << std::endl;
	std::vector<int>nb;
	while (i < ac)
	{
		nb.push_back(std::atoi(av[i]));
		i++;
	}
	std::cout << "Before:  ";
	while (j < nb.size())
	{
		std::cout << nb[j] << " ";
		j++;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::vector<int>print_chain_vector(mergeInsertionSort(nb));
	std::cout << "After:   ";
	j = 0;
	while (j < print_chain_vector.size())
	{
		std::cout << print_chain_vector[j] << " ";
		j++;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	i = 1;
	std::deque<int>n;
	while (i < ac)
	{
		n.push_back(std::atoi(av[i]));
		i++;
	}
	std::cout << "Before:  ";
	j = 0;
	while (j < n.size())
	{
		std::cout << n[j] << " ";
		j++;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::deque<int>print_chain_deque(mergeInsertionSort_deque(n));
	std::cout << "After:   ";
	j = 0;
	while (j < print_chain_deque.size())
	{
		std::cout << print_chain_deque[j] << " ";
		j++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}