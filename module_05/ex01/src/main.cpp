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

#include <Bureaucrat.hpp>
#include <Form.hpp>

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade ";
	out << bureaucrat.getGrade() << ".";
	return (out);
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << "(to_sign : " << form.getTosign();
	out << ", to_exe : " << form.getToexe() << ") is ";
	if (form.getSigned() == true)
		out << "signed.";
	else
		out << "unsigned.";
	return (out);
}

static bool	check_input(int ac, char **av)
{
	int	i = 0;
	int	j = 1;
	int	k = 0;
	int	l = 1;
	int	m = 1;

	if (ac != 6)
		return (false);
	while (std::isalpha(av[1][i]) && ++i);
	while (std::isdigit(av[2][j]) && ++j);
	while (std::isalnum(av[3][k]) && ++k);
	while (std::isdigit(av[4][l]) && ++l);
	while (std::isdigit(av[5][m]) && ++m);
	if (av[1][i] || av[2][j] || av[3][k] || av[4][l] || av[5][m])
		return (false);
	if(!std::atol(av[2]) || !std::atol(av[4]) || !std::atol(av[5]))
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	if (check_input(ac, av) == false)
		return (std::cerr << "Invalid argument !\n", -1);
	try
	{
		Bureaucrat	bureaucrat = Bureaucrat(av[1], std::atol(av[2]));
		Form		form(av[3], std::atol(av[4]), std::atol(av[5]));

		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &exeption)
	{
		std::cerr << exeption.what() << std::endl;
	}
    return (0);
}
