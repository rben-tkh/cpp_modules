/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:41:33 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/20 20:56:02 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

Fixed::Fixed(void) : val(0)
{
	//std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fix)
{
	*this = fix;
	//std::cout << "Copy constructor called\n";
}

Fixed::Fixed(const int new_val) : val(new_val << nb_bits)
{
	//std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float new_val) : val(roundf(new_val * (1 << nb_bits)))
{
	//std::cout << "Float constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &fix)
{
	val = fix.getRawBits();
	//std::cout << "Copy assignment operator called\n";
	return (*this);
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called\n";
}

bool	Fixed::operator>(const Fixed &fix)const
{
	if (toFloat() > fix.toFloat())
		return (1);
	return (0);
}

bool	Fixed::operator<(const Fixed &fix)const
{
	if (toFloat() < fix.toFloat())
		return (1);
	return (0);
}

bool	Fixed::operator>=(const Fixed &fix)const
{
	if (toFloat() >= fix.toFloat())
		return (1);
	return (0);
}

bool	Fixed::operator<=(const Fixed &fix)const
{
	if (toFloat() <= fix.toFloat())
		return (1);
	return (0);
}

bool	Fixed::operator==(const Fixed &fix)const
{
	if (toFloat() == fix.toFloat())
		return (1);
	return (0);
}

bool	Fixed::operator!=(const Fixed &fix)const
{
	if (toFloat() != fix.toFloat())
		return (1);
	return (0);
}

Fixed	Fixed::operator+(const Fixed &fix)const
{
	return (Fixed(toFloat() + fix.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &fix)const
{
	return (Fixed(toFloat() - fix.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &fix)const
{
	return (Fixed(toFloat() * fix.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &fix)const
{
	if (fix.toFloat() != 0.0f)
		return (Fixed(toFloat() / fix.toFloat()));
	return (std::cout << "Impossible to divide\n", *this);
}

Fixed	&Fixed::operator++(void)
{
	return (val++, *this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	return (val++, tmp);
}

Fixed	&Fixed::operator--(void)
{
	return (val--, *this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	return (val--, tmp);
}

int	Fixed::getRawBits(void)const
{
	//std::cout << "getRawBits member function called\n";
	return (val);
}

void	Fixed::setRawBits(int const raw)
{
	val = raw;
}

float	Fixed::toFloat(void)const
{
	return ((float)val / (float)(1 << nb_bits));
}

int		Fixed::toInt(void)const
{
	return (val >> nb_bits);
}

Fixed		&Fixed::min(Fixed &fix1, Fixed &fix2)
{
	if (fix1 < fix2)
		return (fix1);
	return (fix2);
}

const Fixed	&Fixed::min(Fixed const &fix1, Fixed const &fix2)
{
	if (fix1 < fix2)
		return (fix1);
	return (fix2);
}

Fixed		&Fixed::max(Fixed & fix1, Fixed &fix2)
{
	if (fix1 > fix2)
		return (fix1);
	return (fix2);
}

const Fixed	&Fixed::max(Fixed const &fix1, Fixed const &fix2)
{
	if (fix1 > fix2)
		return (fix1);
	return (fix2);
}
