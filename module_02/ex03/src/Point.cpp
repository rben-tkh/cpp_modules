/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:17:53 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/23 15:45:16 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>
#include <Point.hpp>

Point::Point(void) : x(0), y(0){}

Point::Point(const float new_x, const float new_y) : x(new_x), y(new_y){}

Point::Point(const Point &point)
{
	*this = point;
}

Point	&Point::operator=(const Point &point)
{
	Fixed *x = (Fixed *)&this->x;
	Fixed *y = (Fixed *)&this->y;

	*x = point.x;
	*y = point.y;
	return (*this);
}

Point::~Point(void){}

Fixed	Point::getx(void)const
{
	return (x);
}

Fixed	Point::gety(void)const
{
	return (y);
}
