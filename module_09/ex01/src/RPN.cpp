/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:08:26 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/04/04 15:43:26 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) : error(false)
{
	// std::cout << "Default constructor called !\n";
}

RPN::RPN(char *expression) : error(false)
{
	// std::cout << "Constructor called !\n";
	parse(expression);
	exec(expression);
	if (error == false)
		std::cout << nb.top() << std::endl;
}

RPN::RPN(const RPN &rpn)
{
	// std::cout << "Copy constructor called !\n";
	*this = rpn;
}

RPN	&RPN::operator=(const RPN &rpn)
{
	// std::cout << "Copy assignement operator called !\n";
	error = rpn.error;
	nb = rpn.nb;
	return (*this);
}

RPN::~RPN(void)
{
	// std::cout << "Destructor called !\n";
}

bool	RPN::getError(void)const
{
	return (error);
}

std::stack<float>	RPN::getNb(void)const
{
	return (nb);
}

bool RPN::isop(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

void	RPN::parse(char *str)
{
	int	i = 0;
	int	count_nb = 0;
	int	count_op = 0;

	while (str[i] && std::isspace(str[i]))
		i++;
	while (str[i] && error == false)
	{
		if (std::isdigit(str[i]))
			count_nb++;
		else if (isop(str[i]))
			count_op++;
		else if (!std::isspace(str[i]))
			error = true;
		if (count_op >= count_nb || ((std::isdigit(str[i]) || isop(str[i]))
			&& str[i + 1] && str[i + 1] != ' ' && str[i + 1] != '\t'))
			error = true;
		i++;
	}
	if (count_op != (count_nb - 1) || count_nb < 2)
			error = true;
}

void	RPN::exec(char *expression)
{
	float	tmp = 0;
	int		i = 0;

	while (expression[i] && error == false)
	{
		if (std::isdigit(expression[i]))
			nb.push(std::atoi(&expression[i]));
		else if (isop(expression[i]))
		{
			tmp = nb.top();
			nb.pop();
			switch (expression[i])
			{
				case '+':
					nb.top() += tmp;
					break ;
				case '-':
					nb.top() -= tmp;
					break ;
				case '*':
					nb.top() *= tmp;
					break ;
				case '/':
					if (tmp == 0)
						error = true;
					else
						nb.top() /= tmp;
			}
		}
		i++;
	}
}
