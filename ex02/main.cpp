#include "PmergeMe.hpp"

int	main(int ac, char**av)
{
	if (ac == 1)
	{
		std::cout << "Error: Wrong input" << std::endl;
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
	std::cout << std::fixed << elapse_time << " us"<< std::endl;

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
	std::cout << std::fixed << elapse_time << " us" <<std::endl;
	return (0);
}