/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:09:11 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/28 12:09:11 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

bool	check_input(char **av)
{
	int			i = 0;
	int			count = 0;
	std::string	str = av[2];

	for (int i(0); str[i]; i++)
	{
		if (!str.size() || (!std::isalpha(str[i]) && str[i] != ' ' && str[i] != '\t'))
			return (false);
	}
	while (av[1][i] && (std::isdigit(av[1][i]) || av[1][i] == ' '
		|| av[1][i] == '\t' || av[1][i] == '+' || av[1][i] == '-'))
	{
		if (i > 0 && (av[1][i] == '+' || av[1][i] == '-') && std::isdigit(av[1][i - 1]))
			return (false);
		if (i > 0 && (av[1][i - 1] == '+' || av[1][i - 1] == '-') && !std::isdigit(av[1][i]))
			return (false);
		if (std::isdigit(av[1][i]))
			count++;
		i++;
	}
	if (av[1][i] || !count)
		return (false);
	return (true);
}

void get_len(int *len, char **av)
{
	int	i = 0;
	while (av[1][i])
	{
		if (std::isdigit(av[1][i]) && (!av[1][i + 1] || (av[1][i + 1]
			&& (av[1][i + 1] == ' ' || av[1][i + 1] == '\t'))))
			len[0]++;
		i++;
	}
	i = 0;
	while (av[2][i])
	{
		if (std::isalpha(av[2][i]) && (!av[2][i + 1] || (av[2][i + 1]
			&& (av[2][i + 1] == ' ' || av[2][i + 1] == '\t'))))
			len[1]++;
		i++;
	}
}

long	ft_atol(char *str)
{
	static int	i;
	int			n = 1;
	int			count = 0;
	long 		nb = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] && str[i] == '-')
	{
		n = -1;
		i++;
	}
	else if (str[i] && str[i] == '+')
		i++;
	while (str[i] && std::isdigit(str[i]))
	{
		nb = nb * 10 + (str[i++] - '0');
		count++;
	}
	if (count > 10)
		return (ERROR);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (nb * n);
}
