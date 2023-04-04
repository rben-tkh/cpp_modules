/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:57:50 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/03/31 10:57:51 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
		return (std::cerr << "Error\n", -1);

	PmergeMe	pgm(&av[1]);

	if (pgm.getError() == true)
		return (std::cerr << "Error\n", -1);

	return (0);
}
