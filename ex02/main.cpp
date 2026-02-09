#include "PmergeMe.hpp"

int	main(int ac, char**av)
{
	if (ac == 1)
	{
		std::cout << "Error: No input" << std::endl;
		return (1);
	}
	int i = 1;
	PmergeMe list;
	
	std::cout << std::endl;
	std::vector<int>nb;
	while (i < ac)
	{
		if (!list.checkNumbers(av[i]))
		{
			std::cout << "Error: Wrong input" << std::endl;
			return (1);
		}
		nb.push_back(std::atoi(av[i]));
		i++;
	}
	printBefore(nb);
	clock_t begin = clock();
	std::vector<int>sorted_vector(list.mergeInsertionSort(nb));
	clock_t end = clock();
	double elapse_time = double(end - begin) /CLOCKS_PER_SEC;
	printAfter(sorted_vector, ac);
	std::cout << "Time to process a range of " << ac -1 << " elements with std::vector: " << std::fixed << elapse_time << " us"<< std::endl;
	std::cout << std::endl;

	i = 1;
	std::deque<int>n;
	while (i < ac)
	{
		n.push_back(std::atoi(av[i]));
		i++;
	}
	printBefore(n);
	begin = clock();
	std::deque<int>print_chain_deque(list.mergeInsertionSort_deque(n));
	end = clock();
	elapse_time = double(end - begin) /CLOCKS_PER_SEC;
	printAfter(print_chain_deque, ac);
	std::cout << "Time to process a range of " << ac -1 << " elements with std::deque: " << std::fixed << elapse_time << " us"<< std::endl;
	// std::cout << isSorted(print_chain_deque) << std::endl;
	// std::cout << isSorted(sorted_vector) << std::endl;
	return (0);
}