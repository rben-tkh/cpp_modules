/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:41:33 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/18 20:01:26 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : val(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fix)
{
	*this = fix;
	std::cout << "Copy constructor called\n";
}

Fixed::Fixed(const int new_val) : val(new_val << nb_bits)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float new_val) : val(roundf(new_val * (1 << nb_bits)))
{
	std::cout << "Float constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &fix)
{
	val = fix.getRawBits();
	std::cout << "Copy assignment operator called\n";
	return (*this);
}

Fixed::~Fixed(void){std::cout << "Destructor called\n";}

int	Fixed::getRawBits(void)const
{
	std::cout << "getRawBits member function called\n";
	return (val);
}

void	Fixed::setRawBits(int const raw){val = raw;}

float	Fixed::toFloat(void)const
{
	return ((float)val / (float)(1 << nb_bits));
}

int		Fixed::toInt(void)const
{
	return (val >> nb_bits);
}
