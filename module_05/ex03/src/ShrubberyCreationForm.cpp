/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:20:42 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/01 17:48:21 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm(void)
			: Form("ShrubberyCreationForm", 145, 137, "Unknown")
{
	// std::cout << "ShrubberyCreationForm : Default constructor called !\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
			: Form("ShrubberyCreationForm", 145, 137, target)
{
	// std::cout << "ShrubberyCreationForm : Constructor called !\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf)
			: Form("ShrubberyCreationForm", 145, 137, scf.getTarget())
{
	// std::cout << "ShrubberyCreationForm : Copy constructor called !\n";
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf)
{
	// std::cout << "ShrubberyCreationForm : Copy assignement operator called !\n";
	setTarget(scf.getTarget());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	// std::cout << "ShrubberyCreationForm : Default destructor called !\n";
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor)const
{
	beExecuted(executor);
	std::fstream	file;

	file.open((getTarget() + "_shrubbery").c_str(), std::ios_base::out);
	if (!file.is_open())
	{
		std::perror((getTarget() + "_shrubbery").c_str());
		std::remove((getTarget() + "_shrubbery").c_str());
		return ;
	}
	const char	*tree = "          &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n\
	      &\\/(/&/&||/& /_/)_&/_&\n&() &\\/&|()|/&\\/ '%\" & ()\n  &_\\_&&_\\ |&\
	   |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&\
	   &--%---()~\n     &&     \\|||\n             |||\n             |||\n    \
	            |||\n       , -=-~  .-^- _\n";
	file << tree << std::endl << tree << std::endl << tree;
	file.close();
}
