/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:07:34 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/30 21:15:59 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade ";
	out << bureaucrat.getGrade() << ".";
	return (out);
}

static bool	check_input(int ac, char **av)
{
	int	i = 0;
	int	j = 1;

	if (ac != 3)
		return (false);
	while (std::isalpha(av[1][i]) && ++i);
	while (std::isdigit(av[2][j]) && ++j);
	if (av[1][i] || av[2][j] || !std::atol(av[2]))
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	if (check_input(ac, av) == false)
		return (std::cerr << "Invalid argument !\n", -1);
	try
	{
		Bureaucrat bureaucrat(av[1], std::atol(av[2]));
		std::cout << bureaucrat << std::endl; // basic grade

		bureaucrat.upgrade();
		std::cout << bureaucrat << std::endl; // grade -= 1

		bureaucrat.downgrade();
		bureaucrat.downgrade();
		std::cout << bureaucrat << std::endl; // grade += 1
	}
	catch (std::exception &exeption)
	{
		std::cerr << exeption.what() << std::endl;
	}
	return (0);
}
