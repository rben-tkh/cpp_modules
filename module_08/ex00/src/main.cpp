/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 06:56:49 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/03/12 06:56:50 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

bool	check_input(char **av)
{
	long	nb;
	int		j;

	if (TO_FIND > INT_MAX || TO_FIND < INT_MIN)
		return (false);
	for (int i(1); av[i]; i++)
	{
		nb = std::atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (false);
	}
	for (int i(1); av[i] ; i++)
	{
		if (!std::isdigit(av[i][0]) && av[i][0] != '+' && av[i][0] != '-')
			return (false);
		j = 1;
		while (av[i][j] && std::isdigit(av[i][j]))
			j++;
		if (av[i][j] || j > 11)
			return (false);
	}
	return (true);
}

int main(int ac, char **av)
{
	std::list<int>					lst;
	std::list<int>::const_iterator	it;

	if (ac < 2 || check_input(av) == false)
		return (std::cerr << "Invalid arguments !\n", -1);

	for (int i(1); av[i]; i++)
		lst.push_back(std::atoi(av[i]));

	for (it = lst.begin(); it != lst.end() ; it++)
		std::cout << *it << ' ';

	if (easyfind(lst, TO_FIND))
		std::cout << std::endl << TO_FIND << " finded !\n";
	else
		std::cout << std::endl << TO_FIND << " not found !\n";

    return (0);
}
