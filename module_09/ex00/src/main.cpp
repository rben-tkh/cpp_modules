/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:40:06 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/03/30 14:46:46 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "error: Invalid argument\n", -1);
	std::fstream csv("data.csv");
	if (!csv.is_open())
			return (std::perror("data.csv"), -1);
	std::fstream txt(av[1]);
	if (!txt.is_open())
			return (std::perror(av[1]), txt.close(), -1);

	std::ostringstream ss_csv;
	std::ostringstream ss_txt;
	ss_csv << csv.rdbuf();
	ss_txt << txt.rdbuf();

	BitcoinExchange	data(ss_csv.str(), ss_txt.str());

	if (data.getError() == true)
		return (csv.close(), txt.close(), -1);

	return (csv.close(), txt.close(), 0);
}
