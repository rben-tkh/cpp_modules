/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:45:41 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/12/25 13:45:41 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if (ac > 1 && av)
	{
		for (int i(1); av[i]; i++)
		{
			for (int j(0); av[i][j]; j++)
				std::cout << (char)toupper(av[i][j]);
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	return (std::cout << std::endl, 0);
}
