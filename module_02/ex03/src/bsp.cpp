/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:17:59 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/20 20:56:11 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Point.hpp>

static Fixed	get_vec(Point vec1, Point vec2, Point point)
{
	Fixed res = ((vec1.getx() - point.getx()) * (vec2.gety() - point.gety())
	- (vec1.gety() - point.gety()) * (vec2.getx() - point.getx()));

	return (res);
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed	res1 = get_vec(a, b, point);
	Fixed	res2 = get_vec(b, c, point);
	Fixed	res3 = get_vec(c, a, point);

	if ((res1 > 0 && res2 > 0 && res3 > 0)
		|| (res1 < 0 && res2 < 0 && res3 < 0))
		return (1);
	return (0);
}
