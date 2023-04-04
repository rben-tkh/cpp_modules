/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:34:32 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/11 18:24:14 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl hamid;

	std::cout << "[DEBUG]\n";
	hamid.complain("DEBUG");
	std::cout << "[INFO]\n";
	hamid.complain("INFO");
	std::cout << "[WARNING]\n";
	hamid.complain("WARNING");
	std::cout << "[ERROR]\n";
	hamid.complain("ERROR");
	return (0);
}
