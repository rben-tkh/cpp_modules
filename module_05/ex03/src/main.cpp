/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:07:34 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/01 18:37:12 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <Intern.hpp>
#include <Form.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

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

int	main(void)
{
	Bureaucrat	boss("Rayan", 1);
	Bureaucrat	adjoint("Ilyes", 70);
	Intern		noob;
	Form		*shrubbery;
	Form		*robotomy;
	Form		*presidential;

	std::cout << "\n/*----------SHRUBBERY_TEST----------*/\n\n";

	if ((shrubbery = noob.makeForm("shrubbery creation", "Bender")))
	{
		adjoint.executeForm(*shrubbery);
		adjoint.signForm(*shrubbery);
		adjoint.executeForm(*shrubbery);
	}

	std::cout << "\n/*----------ROBOTOMY_TEST----------*/\n\n";

	if ((robotomy = noob.makeForm("robotomy request", "Bender")))
	{
		adjoint.signForm(*robotomy);
		adjoint.executeForm(*robotomy);
		boss.executeForm(*robotomy);
	}

	std::cout << "\n/*----------PRESIDENTIAL_TEST----------*/\n\n";

	if ((presidential = noob.makeForm("presidential pardon", "Bender")))
	{
		adjoint.signForm(*presidential);
		boss.signForm(*presidential);
		boss.executeForm(*presidential);
	}

	std::cout << "\n/*----------DELETING_ALL----------*/\n\n";

	return (delete shrubbery, delete robotomy, delete presidential, 0);
}
