/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:17:43 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/24 13:28:43 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# define ERROR 1001.0f
# define MIN -1000.0f
# define MAX 1000.0f

# define CYAN "\033[1;3;36m"
# define YELLOW "\033[0;3;33m"
# define GREEN "\033[0;3;32m"
# define RED "\033[0;3;31m"
# define UNDER "\033[4m"
# define INVISIBLE "\033[?25l"
# define VISIBLE "\033[?25h"
# define RESET "\033[0m"
# define CLEAR "\033[H\033[2J"

# include <Fixed.hpp>
# include <csignal>
# include <fstream>

/*----------------------------------C_POINT----------------------------------*/

class Point
{
	public:
				Point(void);
				Point(const float new_x, const float new_y);
				Point(const Point &point);
		Point	&operator=(const Point &point);
				~Point(void);

		Fixed	getx(void)const;
		Fixed	gety(void)const;

	private:
		const Fixed	x;
		const Fixed	y;
};

/*------------------------------------BSP------------------------------------*/

Point	*get_points(void);
bool	check_points(const Point a, const Point b, const Point c);
bool	bsp(const Point a, const Point b, const Point c, const Point point);
void	print_status(const Point a, const Point b, const Point c, const Point point, std::ostream &out, char x);
void	check_bsp(const Point a, const Point b, const Point c, const Point point, std::ostream &out);
bool	save(const Point a, const Point b, const Point c, const Point point);
bool	check_continue(void);

/*------------------------------------T^T------------------------------------*/

#endif
