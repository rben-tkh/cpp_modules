/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:33:16 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/15 18:42:42 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Data::Data(void) : error(0), c(0), i(0), f(0), d(0)
{
	// std::cout << "Default constructor called !\n"
}

Data::Data(double nb)
		: error(0), c(toChar(nb)), i(toInt(nb)), f(toFloat(nb)), d(nb)
{
	// std::cout << "Constructor called !\n"
}

Data::Data(const Data &data) : error(0), c(0), i(0), f(0), d(0)
{
	*this = data;
	// std::cout << "Copy constructor called !\n"
}

Data	&Data::operator=(const Data &data)
{
	// std::cout << "Copy assignement operator called !\n"
	error = data.error;
	c = data.c;
	i = data.i;
	f = data.f;
	d = data.d;
	return (*this);
}

Data::~Data(void)
{
	// std::cout << "Default destructor called !\n"
}

int	Data::getError(void)const
{
	return (error);
}

char	Data::getC(void)const
{
	return (c);
}

int	Data::getI(void)const
{
	return (i);
}

float	Data::getF(void)const
{
	return (f);
}

double	Data::getD(void)const
{
	return (d);
}

char	Data::toChar(double nb)
{
	char res = static_cast<char>(nb);

	if (!std::isfinite(nb) || nb < CHAR_MIN || nb > CHAR_MAX)
		return (error += 4, 0);
	if (!std::isprint(res))
		return (error += 2, 0);
	return (res);
}

int	Data::toInt(double nb)
{
	if (!std::isfinite(nb) || nb < INT_MIN || nb > INT_MAX)
		return (error += 1, 0);
	return (static_cast<int>(nb));
}

float	Data::toFloat(double nb)
{
	return (static_cast<float>(nb));
}
