/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:07:34 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/01 18:41:02 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
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
	Form		*shrubbery;
	Form		*robotomy;
	Form		*presidential;

	std::cout << "\n/*----------SHRUBBERY_TEST----------*/\n\n";

	shrubbery = new ShrubberyCreationForm("garden");
	adjoint.executeForm(*shrubbery);
	adjoint.signForm(*shrubbery);
	adjoint.executeForm(*shrubbery);

	std::cout << "\n/*----------ROBOTOMY_TEST----------*/\n\n";

	robotomy = new RobotomyRequestForm("w.c");
	adjoint.signForm(*robotomy);
	adjoint.executeForm(*robotomy);
	boss.executeForm(*robotomy);

	std::cout << "\n/*----------PRESIDENTIAL_TEST----------*/\n\n";

	presidential = new PresidentialPardonForm("noob");
	adjoint.signForm(*presidential);
	boss.signForm(*presidential);
	boss.executeForm(*presidential);

	std::cout << "\n/*----------DELETING_ALL----------*/\n\n";

	return (delete shrubbery, delete robotomy, delete presidential, 0);
}
