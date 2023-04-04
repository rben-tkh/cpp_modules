/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 03:57:10 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/01 03:57:11 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Intern.hpp>

Intern::Intern(void)
{
	// std::cout << "Intern : Default constructor called !\n";
	form[0] = "shrubbery creation";
	form[1] = "robotomy request";
	form[2] = "presidential pardon";
}

Intern::Intern(const Intern &intern)
{
	// std::cout << "Intern : Copy constructor called !\n";
	(void)intern;
	form[0] = "shrubbery creation";
	form[1] = "robotomy request";
	form[2] = "presidential pardon";
}

Intern	&Intern::operator=(const Intern &intern)
{
	// std::cout << "Intern : Copy assignement operator called !\n";
	(void)intern;
	return(*this);
}

Intern::~Intern(void)
{
	// std::cout << "Intern : Default destructor called !\n";
}

Form	*Intern::makeForm(const std::string name, std::string target)
{
	int	i = 0;
	while(i < 3 && name != form[i] && ++i);
	switch (i)
	{
		case (0):
			return (new ShrubberyCreationForm(target));
		case (1):
			return (new RobotomyRequestForm(target));
		case (2):
			return (new PresidentialPardonForm(target));
		default:
			std::cout << "An intern want to create a form that does not exist !\n";
	}
	return (NULL);
}
