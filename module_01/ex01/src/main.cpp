/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:03 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/11 16:08:18 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static size_t	ft_atos(char *str)
{
	size_t	nb = 0;
	int		i = -1;
	int		count = 0;

	i = 0;
	while (str[i])
	{
		nb = nb * 10 + (str[i++] - '0');
		count++;
	}
	if (str[i] || count > 2 || nb > 42)
			return (std::cout << "Invalid argument !\n", 0);
	return (nb);
}

int	main(int ac, char **av)
{
	Zombie	*bizon;
	size_t	nb;

	if (ac == 3 && av)
	{
		nb = ft_atos(av[1]);
		if (nb == 0)
			return (-1);
		bizon = zombieHorde(nb, av[2]);
		delete[](bizon);
	}
	else
		return (std::cout << "Invalid arguments !\n", -1);
	return (0);
}
