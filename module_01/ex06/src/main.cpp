/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:34:32 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/11 18:30:11 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	hamid;

	if (ac != 2)
		return (std::cout << "Invalid arguments\n", -1);
	switch (hamid.get_level(av[1]))
	{
		case DEBUG:
			std::cout << "[DEBUG]\n";
			hamid.complain("DEBUG");
		case INFO:
			std::cout << "[INFO]\n";
			hamid.complain("INFO");
		case WARNING:
			std::cout << "[WARNING]\n";
			hamid.complain("WARNING");
		case ERROR:
			std::cout << "[ERROR]\n";
			hamid.complain("ERROR");
			break ;
		default:
			hamid.complain("HALALMOD");
			break ;
	}
	return (0);
}
