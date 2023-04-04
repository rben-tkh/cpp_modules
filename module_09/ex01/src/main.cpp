/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:08:30 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/03/30 16:17:10 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cerr << "Error\n", -1);

	RPN	rpn(av[1]);

	if (rpn.getError() == true)
		return (std::cerr << "Error\n", -1);

	return (0);
}
