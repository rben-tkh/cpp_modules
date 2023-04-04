/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:49:46 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/01 19:44:50 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <cctype>
# include <exception>
# include <fstream>
# include <ctime>
# include <Bureaucrat.hpp>

class Bureaucrat;

/*----------------------------------C_FORM-----------------------------------*/

class Form
{
	public:
							Form(void);
							Form(const std::string new_name, int new_to_sign, int new_to_exe, const std::string new_target);
							Form(const Form &form);
		Form				&operator=(const Form &form);
		virtual				~Form(void);

		const std::string	getName(void)const;
		bool				getSigned(void)const;
		int					getTosign(void)const;
		int					getToexe(void)const;
		std::string			getTarget(void)const;
		void				setTarget(std::string new_target);

		void				beSigned(const Bureaucrat &Bureaucrat);
		void				beExecuted(const Bureaucrat &ref)const;
		virtual void		execute(const Bureaucrat &executor)const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				const char	*what(void)const throw();
		};

	private:
		const std::string	name;
		bool				is_signed;
		const int			to_sign;
		const int			to_exe;
		std::string			target;
};

/*---------------------------------OPERATOR----------------------------------*/

std::ostream	&operator<<(std::ostream &out, const Form &form);

/*------------------------------------T^T------------------------------------*/

#endif
