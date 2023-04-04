/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:20:46 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/31 14:20:47 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <Form.hpp>

/*--------------------------C_ROBOTOMYREQUESTFORM-------------------------*/

class RobotomyRequestForm : public Form
{
	public:
							RobotomyRequestForm(void);
							RobotomyRequestForm(const std::string target);
							RobotomyRequestForm(const RobotomyRequestForm &rrf);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &rrf);
		virtual				~RobotomyRequestForm(void);

		void				execute(const Bureaucrat &executor)const;
};

/*------------------------------------T^T------------------------------------*/

#endif
