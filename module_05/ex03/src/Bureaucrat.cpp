/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:53:15 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/01 19:39:58 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(void) : name("Unknown"), grade(GRADE_MIN)
{
	std::cout << name << " join the venture and take the grade " << grade << " !\n";
}

Bureaucrat::Bureaucrat(const std::string new_name, int new_grade)
					: name(new_name), grade(new_grade)
{
	if (grade < GRADE_MAX)
		throw GradeTooHighException();
	else if (grade > GRADE_MIN)
		throw GradeTooLowException();
	std::cout << name << " join the venture and take the grade " << grade << " !\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.name)
{
	std::cout << bureaucrat.name << " is duplicated !\n";
	*this = bureaucrat;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	std::cout << name << " copies " << bureaucrat.name << "'s rank !\n";
	grade = bureaucrat.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << name << " left the venture !\n";
}

const std::string	Bureaucrat::getName(void)const
{
	return (name);
}

int	Bureaucrat::getGrade(void)const
{
	return (grade);
}

void	Bureaucrat::upgrade(void)
{
	if ((grade - 1) < GRADE_MAX)
		throw GradeTooHighException();
	grade--;
}

void	Bureaucrat::downgrade(void)
{
	if ((grade + 1) > GRADE_MIN)
		throw GradeTooLowException();
	grade++;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
			form.beSigned(*this);
			std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &exeption)
	{
			std::cout << name << " could'nt sign " << form.getName();
			std::cout << " because :\n" << exeption.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const Form &form)
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch(std::exception &exeption)
	{
		std::cout << name << " could not execute " << form.getName();
		std::cout << " because :\n" << exeption.what() << std::endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what(void)const throw()
{
	return ("The bureaucrat's grade is too high.");
}

const char	*Bureaucrat::GradeTooLowException::what(void)const throw()
{
	return ("The bureaucrat's grade is too low.");
}
