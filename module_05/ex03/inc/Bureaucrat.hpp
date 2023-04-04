/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:53:13 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/01 17:32:02 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define GRADE_MIN 150
# define GRADE_MAX 1

# include <Form.hpp>

class Form;

/*--------------------------------C_BUREAUCRAT-------------------------------*/

class Bureaucrat
{
	public:
							Bureaucrat(void);
							Bureaucrat(const std::string new_name, int new_grade);
							Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat			&operator=(const Bureaucrat &bureaucrat);
							~Bureaucrat(void);

		const std::string	getName(void)const;
		int					getGrade(void)const;

		void				upgrade(void);
		void				downgrade(void);
		void				signForm(Form &form);
		void				executeForm(const Form &form);

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
		int					grade;
};

/*---------------------------------OPERATOR----------------------------------*/

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

/*------------------------------------T^T------------------------------------*/

#endif
