/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:49:46 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/01 19:55:10 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <Bureaucrat.hpp>

class Bureaucrat;

/*----------------------------------C_FORM-----------------------------------*/

class Form
{
	public:
							Form(void);
							Form(const std::string new_name, const int new_to_sign, const int new_to_exe);
							Form(const Form &form);
		Form				&operator=(const Form &form);
							~Form(void);

		const std::string	getName(void)const;
		bool				getSigned(void)const;
		int					getTosign(void)const;
		int					getToexe(void)const;

		void				beSigned(const Bureaucrat &Bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what(void)const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what(void)const throw();
		};

	private:
		const std::string	name;
		bool				is_signed;
		const int			to_sign;
		const int			to_exe;
};

/*---------------------------------OPERATOR----------------------------------*/

std::ostream	&operator<<(std::ostream &out, const Form &form);

/*------------------------------------T^T------------------------------------*/

#endif
