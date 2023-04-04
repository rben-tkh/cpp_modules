/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:49:39 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/01 19:57:06 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Form.hpp>

Form::Form(void) : name("Unknown"), is_signed(false), to_sign(GRADE_MIN), to_exe(GRADE_MIN)
{
	std::cout << name << " created (to_sign : " << to_sign;
	std::cout << ", to_exe : " << to_exe << ") !\n";
}
Form::Form(const std::string new_name, int new_to_sign, int new_to_exe, const std::string new_target)
		: name(new_name), is_signed(false), to_sign(new_to_sign), to_exe(new_to_exe), target(new_target)
{
	if (to_sign < GRADE_MAX || to_exe < GRADE_MAX)
		throw GradeTooHighException();
	else if (to_sign > GRADE_MIN || to_exe > GRADE_MIN)
		throw GradeTooLowException();
	std::cout << name << " created (to_sign : " << to_sign;
	std::cout << ", to_exe : " << to_exe;
	std::cout << ", target : " << target << ") !\n";
}

Form::Form(const Form &form) : name(form.name), to_sign(form.to_sign), to_exe(form.to_exe)
{
	std::cout << name << "is duplicated !\"";
	*this = form;
}

Form	&Form::operator=(const Form &form)
{
	std::cout << name << " copies " << form.name << "'s data !\n";
	is_signed = form.is_signed;
	target = form.target;
	return (*this);
}

Form::~Form(void)
{
	std::cout << name << " was destroyed !\n";
}

const std::string	Form::getName(void)const
{
	return (name);
}

bool	Form::getSigned(void)const
{
	return (is_signed);
}

int	Form::getTosign(void)const
{
	return (to_sign);
}

int	Form::getToexe(void)const
{
	return (to_exe);
}

std::string	Form::getTarget(void)const
{
	return (target);
}

void	Form::setTarget(std::string new_target)
{
	target = new_target;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > to_sign)
		throw GradeTooLowException();
	is_signed = true;
}

void	Form::beExecuted(const Bureaucrat &ref)const
{
	if (is_signed == false)
		throw Form::FormNotSignedException();
	else if (ref.getGrade() > getToexe())
		throw Form::GradeTooLowException();
}

const char	*Form::GradeTooHighException::what(void)const throw()
{
	return ("The form's grade is too high.");
}

const char	*Form::GradeTooLowException::what(void)const throw()
{
	return ("The form's grade is too low.");
}

const char	*Form::FormNotSignedException::what(void)const throw()
{
	return ("The form is not signed.");
}
