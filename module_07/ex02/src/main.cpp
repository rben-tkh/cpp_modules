/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:11:42 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/20 00:11:43 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(int ac, char **av)
{
	if (ac != 2 || !av || !av[0] || !av[1])
		return (std::cerr << "Invalid argument !\n", -1);
	int	i = 0;
	if (av[1][i] == '+')
		i++;
	while (av[1][i] && std::isdigit(av[1][i]) && ++i);
	long long	max_val = std::atoll(av[1]);
	if (av[1][i] || !max_val || max_val > 42)
		return (std::cerr << "Invalid argument !\n",-1);

	Array<int> numbers(max_val);
	int	*mirror = new int[max_val];
	srand(time(NULL));
	for (int i = 0; i < max_val; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << "size of array = " << numbers.size() << std::endl;
	std::cout << "\nrandom number(s) :\n\n";
	for (int i = 0; numbers.getArray(0) && i < numbers.size(); i++)
				std::cout << numbers.getArray(i) << std::endl;

    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		std::cout << "\nassigement operator and copy number(s) :\n\n";
		for (int i = 0; test.getArray(0) && i < test.size(); i++)
				std::cout << test.getArray(i) << std::endl;
		std::cout << std::endl;
    }

	for (int i = 0; i < max_val; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value !!\n";
			return (1);
		}
	}
	try
	{
		std::cout << "array[-2] = " << numbers[-2] << std::endl;
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << '\n';
	}
	try
	{
		std::cout << "array[max_val] = " << numbers[max_val + 5] << std::endl;
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << '\n';
	}
	try
	{
		std::cout << "array[max_val - 1] = " << numbers[max_val - 1] << std::endl;
	}
	catch(const std::exception &exception)
	{
		std::cerr << exception.what() << '\n';
	}

	for (int i(0); i < max_val; i++)
        numbers[i] = rand();
	std::cout << "\nnew number(s) :\n\n";
	for (int i = 0; numbers.getArray(0) && i < numbers.size(); i++)
				std::cout << numbers.getArray(i) << std::endl;

	return (delete []mirror, 0);
}
