/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:36:35 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/24 13:39:05 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Point.hpp>

static float ft_stof(std::string str)
{
	float	nb = 0;
	int		n = 1;
	int		i = 0;
	int		count = 1;
	float	pow = 1;

	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] && str[i] == '-')
	{
		n *= -1;
		i++;
	}
	if (!str[i])
		return (ERROR);
	while (str[i] && str[i] == '0')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i++] - '0');
		count++;
	}
	if (nb < MIN || nb > MAX || count > 5 || (str[i]
		&& str[i] != '.' && str[i] != ','))
		return (ERROR);
	else if (str[i] && (str[i] == '.' || str[i] == ',') && !str[++i])
		return (ERROR);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb + (float)(str[i++] - '0') / (10.0f * pow);
		pow *= 10.0f;
	}
	if (str[i])
		return (ERROR);
	return (nb * n);
}

static float	get_axe(char c, char point)
{
	float		axe = ERROR;
	std::string	str;

	while (axe < MIN || axe > MAX)
	{
		if (std::cin.fail())
			return (ERROR);
		std::cout << "> Enter the " << c << " of " << point << " : ";
		if (!std::getline(std::cin, str))
			return (ERROR);
		axe = ft_stof(str);
		std::cout << std::endl;
		if (str.empty() || axe < MIN || axe > MAX)
			std::cout << RED << "Invalid input, try again !\n\n" << YELLOW;
	}
	return (axe);
}

Point	*get_points(void)
{
	Point	*points = new Point[4];

	points[0] = Point(get_axe('X', 'A'), get_axe('Y', 'A'));
	if (points[0].getx().toFloat() < MIN || points[0].getx().toFloat() > MAX
		|| points[0].gety().toFloat() < MIN || points[0].gety().toFloat() > MAX)
		return (std::cout << CYAN << CLEAR "\t\t\t*** GOODBYE ***\n\n\n", \
		points[0] = Point(ERROR, ERROR), points);
	points[1] = Point(get_axe('X', 'B'), get_axe('Y', 'B'));
	if (points[1].getx().toFloat() < MIN || points[1].getx().toFloat() > MAX
		|| points[1].gety().toFloat() < MIN || points[1].gety().toFloat() > MAX)
		return (std::cout << CYAN << CLEAR "\t\t\t*** GOODBYE ***\n\n\n", \
		points[1] = Point(ERROR, ERROR), points);
	points[2] = Point(get_axe('X', 'C'), get_axe('Y', 'C'));
	if (points[2].getx().toFloat() < MIN || points[2].getx().toFloat() > MAX
		|| points[2].gety().toFloat() < MIN || points[2].gety().toFloat() > MAX)
		return (std::cout << CYAN << CLEAR "\t\t\t*** GOODBYE ***\n\n\n", \
		points[2] = Point(ERROR, ERROR), points);
	points[3] = Point(get_axe('X', 'P'), get_axe('Y', 'P'));
	if (points[3].getx().toFloat() < MIN || points[3].getx().toFloat() > MAX
		|| points[3].gety().toFloat() < MIN || points[3].gety().toFloat() > MAX)
		return (std::cout << CYAN << CLEAR "\t\t\t*** GOODBYE ***\n\n\n", \
		points[3] = Point(ERROR, ERROR), points);
	return (points);
}

bool	check_points(const Point a, const Point b, const Point c)
{
	if (a.getx().toFloat() * (b.gety().toFloat() - c.gety().toFloat())
		+ b.getx().toFloat() * (c.gety().toFloat() - a.gety().toFloat()) + c.getx().toFloat()
		* (a.gety().toFloat() - b.gety().toFloat()))
		return (1);
	return (0);
}

void	print_status(const Point a, const Point b, const Point c, const Point point, std::ostream &out, char x)
{
		if (out == std::cout && x == 'i')
			out << GREEN;
		else if (out == std::cout && x == 'o')
			out << RED;
		else
			out << "\t    *** Binary Space Partitioning ***\n\nFor :\n";
		out << "- A(" << a.getx().toFloat() << ", " << a.gety().toFloat() << ")\n";
		out << "- B(" << b.getx().toFloat() << ", " << b.gety().toFloat() << ")\n";
		out << "- C(" << c.getx().toFloat() << ", " << c.gety().toFloat() << ")\n\n";
		if (out == std::cout)
			out << UNDER;
		out << "The point P(";
		out << point.getx().toFloat() << ", " << point.gety().toFloat();
		out << ") is ";
		if (x == 'i')
			out << "inside";
		else
			out << "outside";
		out << " the triangle ABC !\n";
		if (out == std::cout)
			std::cout << std::endl;
}

static bool	check_save(void)
{
	std::string	str;

	while (str.empty())
	{
		std::cout << YELLOW << "> Do you want to save the result ? ";
		if (!std::getline(std::cin, str))
			return (std::cout << std::endl, 1);
		if (str.empty() || (str != "yes" && str != "no" && str != "y" && str != "n"
			&& str != "YES" && str != "NO" && str != "y" && str != "n" && str != "Y" && str != "N"))
		{
			std::cout << RED << "\nInvalid input, try again !\n\n";
			str.clear();
		}
		if (str == "no" || str == "NO" || str == "n" || str == "N")
			return (std::cout << std::endl, 1);
	}
	return (std::cout << YELLOW << std::endl, 0);
}

bool	save(const Point a, const Point b, const Point c, const Point point)
{
	std::fstream file;
	std::string	s1;

	if (!check_save())
	{
		while (s1.empty())
		{
			std::cout << YELLOW << "> Enter the backup file name or path : ";
			if (!std::getline(std::cin, s1))
				return (std::cout << CYAN CLEAR << "\t\t\t*** GOODBYE ***\n\n\n", 1);
			file.open((char *)&s1[0], std::ios_base::out);
			if (!file.is_open())
			{
				std::cout << RED << std::endl;
				std::perror(NULL);
				std::cout << std::endl;
				s1.clear();
			}
		}
		check_bsp(a, b, c, point, file);
		return (std::cout << std::endl, file.close(), 0);
	}
	return (0);
}

bool	check_continue(void)
{
	std::string	str;

	if (std::cin.fail())
		return (std::cout << CYAN CLEAR "\t\t\t*** GOODBYE ***\n\n\n", 1);
	while (str.empty())
	{
		std::cout << YELLOW << "> Do you want to continue ? ";
		if (!std::getline(std::cin, str))
			return (std::cout << CYAN CLEAR "\t\t\t*** GOODBYE ***\n\n\n", 1);
		if (str.empty() || (str != "yes" && str != "no" && str != "y" && str != "n"
			&& str != "YES" && str != "NO" && str != "y" && str != "n" && str != "Y" && str != "N"))
		{
			std::cout << RED << "\nInvalid input, try again !\n\n";
			str.clear();
		}
		if (str == "no" || str == "NO" || str == "n" || str == "N")
			return (std::cout << CYAN CLEAR "\t\t\t*** GOODBYE ***\n\n\n", 1);
	}
	return (std::cout << CYAN, 0);
}
