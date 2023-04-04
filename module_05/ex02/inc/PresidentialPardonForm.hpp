/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:20:56 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/31 14:20:57 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <Form.hpp>

/*--------------------------C_PRESIDENTIALPARDONFORM-------------------------*/

class PresidentialPardonForm : public Form
{
	public:
								PresidentialPardonForm(void);
								PresidentialPardonForm(const std::string target);
								PresidentialPardonForm(const PresidentialPardonForm &ppf);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &ppf);
		virtual					~PresidentialPardonForm(void);

		void					execute(const Bureaucrat &executor)const;
};

/*------------------------------------T^T------------------------------------*/

#endif
