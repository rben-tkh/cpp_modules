/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:21:01 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/01 17:48:26 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm(void)
			: Form("PresidentialPardonForm", 25, 5, "Unknown")
{
	// std::cout << "PresidentialPardonForm : Default constructor called !\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
			: Form("PresidentialPardonForm", 25, 5, target)
{
	// std::cout << "PresidentialPardonForm : Constructor called !\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf)
			: Form("PresidentialPardonForm", 25, 5, ppf.getTarget())
{
	// std::cout << "PresidentialPardonForm : Copy constructor called !\n";
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf)
{
	// std::cout << "PresidentialPardonForm : Copy assignement operator called !\n";
	setTarget(ppf.getTarget());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	// std::cout << "PresidentialPardonForm : Default destructor called !\n";
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor)const
{
	beExecuted(executor);
	std::cout << getTarget() << " has been forgiven by Zaphod Beeblebrox.\n";
}
