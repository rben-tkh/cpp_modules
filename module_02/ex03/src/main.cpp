/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:39:28 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/23 16:05:01 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>
#include <Point.hpp>

std::ostream	&operator<<(std::ostream &out, const Fixed &fix)
{
	out << fix.toFloat();
	return (out);
}

void	check_bsp(const Point a, const Point b, const Point c, const Point point, std::ostream &out)
{
	if (!check_points(a, b, c))
	{
			if (out == std::cout)
				out << RED;
			else
				out << "\t    *** Binary Space Partitioning ***\n\nFor :\n";
			out << "- A(" << a.getx().toFloat() << ", " << a.gety().toFloat() << ")\n";
			out << "- B(" << b.getx().toFloat() << ", " << b.gety().toFloat() << ")\n";
			out << "- C(" << c.getx().toFloat() << ", " << c.gety().toFloat() << ")\n";
			if (out == std::cout)
				out << UNDER;
			out << "\nThe points A, B and C don't form a triangle !\n";
			if (out == std::cout)
				std::cout << std::endl;
	}
	else if (bsp(a, b, c, point))
		print_status(a, b, c, point, out, 'i');
	else
		print_status(a, b, c, point, out, 'o');
}

int	main(void)
{
	Point	*points;

	std::signal(SIGQUIT, SIG_IGN);
	std::signal(SIGINT, SIG_IGN);
	while (42)
	{
		std::cout << CLEAR CYAN INVISIBLE;
		std::cout << "\t     *** Binary Space Partitioning ***\n";
		std::cout << "\tPlease, enter values between 1000 and -1000\n";
		std::cout << "\t\t  (Press CTRL-D to exit)\n\n" << YELLOW;
		points = get_points();
		if (points[0].getx().toFloat() > MAX || points[1].getx().toFloat() > MAX
			|| points[2].getx().toFloat() > MAX || points[3].getx().toFloat() > MAX)
			return (delete[](points), std::cout << RESET VISIBLE, 0);
		else
			check_bsp(points[0], points[1], points[2], points[3], std::cout);
		if (save(points[0], points[1], points[2], points[3]) || check_continue())
			return (delete[](points), std::cout << RESET VISIBLE, 0);
		delete[](points);
	}
	return (delete[](points), std::cout << RESET VISIBLE, 0);
}

//https://www.geogebra.org/calculator
