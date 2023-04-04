/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 03:57:06 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/01 03:57:17 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <Form.hpp>
# include <ShrubberyCreationForm.hpp>
# include <RobotomyRequestForm.hpp>
# include <PresidentialPardonForm.hpp>

/*----------------------------------C_INTERN---------------------------------*/

class Intern
{
	public:
				Intern(void);
				Intern(const Intern &intern);
		Intern	&operator=(const Intern &intern);
				~Intern(void);

		Form	*makeForm(const std::string fname, std::string target);

	private:
		std::string	form[3];
};

/*------------------------------------T^T------------------------------------*/

#endif
