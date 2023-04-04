/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:20:50 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/01 18:00:06 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm(void)
			: Form("RobotomyRequestForm", 72, 45, "Unknown")
{
	// std::cout << "RobotomyRequestForm : Default constructor called !\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
			: Form("RobotomyRequestForm", 72, 45, target)
{
	// std::cout << "RobotomyRequestForm : Constructor called !\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf)
			: Form("RobotomyRequestForm", 72, 45, rrf.getTarget())
{
	// std::cout << "RobotomyRequestForm : Copy constructor called !\n";
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf)
{
	// std::cout << "RobotomyRequestForm : Copy assignement operator called !\n";
	setTarget(rrf.getTarget());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	// std::cout << "RobotomyRequestForm : Default destructor called !\n";
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor)const
{
	beExecuted(executor);
	std::cout << "TAGTAGTAG BOOMBOOMBOOM RATATATA\n";
	std::srand(std::time(NULL));
	if (std::rand() % 2)
		std::cout << "Successful operation, " << getTarget() << " is robotomized !\n";
	else
		std::cout << "Operation failed, " << getTarget() << " is not robotomized !\n";	
}
