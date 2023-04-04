/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:02:48 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/24 21:37:48 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(int ac, char **av)
{
	int	len[2] = {0, 0};

	if (ac != 3 || !av[1] || !av[2] || check_input(av) == false)
		return (std::cerr << "Invalid arguments !\n", -1);

	std::cout << "\n\t*** ARRAY OF INT ***\n";
	get_len(len, av);
	int	itab[len[0]];
	long long	nb;
	for (int i(0); i < len[0]; i++)
	{
		nb = ft_atol(av[1]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (std::cerr << "Invalid arguments !\n", -1);
		itab[i] = static_cast<int>(nb);
	}
	iter(itab, len[0], print<int>);

	std::cout << "\n\t*** ARRAY OF ALPHA STRING ***\n\n";

	int i = 0;
	char	*stab[len[1] + 1];
	char	*str = std::strtok(av[2], " \t");
    while (str)
	{
		stab[i] = str;
        str = std::strtok(NULL, " \t");
		i++;
    }
	stab[i] = str;
	iter(stab, len[1], print<char *>);

	return (0);
}
