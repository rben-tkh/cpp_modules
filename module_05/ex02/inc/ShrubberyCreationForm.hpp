/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:20:38 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/01 17:32:10 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERCREATIONFORM_HPP
# define SHRUBBERCREATIONFORM_HPP

# include <Form.hpp>

/*--------------------------C_SHRUBBERCREATIONFORM-------------------------*/

class ShrubberyCreationForm : public Form
{
	public:
								ShrubberyCreationForm(void);
								ShrubberyCreationForm(const std::string target);
								ShrubberyCreationForm(const ShrubberyCreationForm &scf);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &scf);
		virtual					~ShrubberyCreationForm(void);

		void					execute(const Bureaucrat &executor)const;
};

/*------------------------------------T^T------------------------------------*/

#endif
