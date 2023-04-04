/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:55:02 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/15 18:47:03 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

static bool	check_input(char *str)
{
	std::string	check = str;
	int	i = 0;
	int	count = 0;

	if (check == "nan" || check == "-inf" || check == "inf" || check == "+inf")
		return (true);
	else if (check == "nanf" || check == "-inff" || check == "inff" || check == "+inff")
		return (true);
	else if (check.size() == 1)
		return (true);
	else if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] && str[i] >= '0' && str[i] <= '9') || (str[i] && str[i] == '.'))
	{
		if (str[i] == '.')
			count++;
		i++;
	}
	if (count > 1)
		return (false);
	else if ((str[i] && str[i] != 'f') || (str[i] && str[i] == 'f' && str[i + 1]))
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	if (ac != 2 || !av[1] || check_input(av[1]) == false)
		return (std::cerr << "Invalid argument !\n", -1);
	if (av[1] && av[1][0] && !av[1][1] && !std::isdigit(av[1][0]))
		return (reverse(av[1][0]), 0);
	double	res = std::atof(av[1]);
	toChar(res);
	toInt(res);
	std::cout << std::fixed << std::setprecision(1);
	toFloat(res);
	std::cout << "double : " << res << std::endl;
	return (0);
}
