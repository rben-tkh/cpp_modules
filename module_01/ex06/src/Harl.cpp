/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:34:21 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/11 18:31:59 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	lvl[0] = "DEBUG";
	ptr[0] = &Harl::debug;
	lvl[1] = "INFO";
	ptr[1] = &Harl::info;
	lvl[2] = "WARNING";
	ptr[2] = &Harl::warning;
	lvl[3] = "ERROR";
	ptr[3] = &Harl::error;
	lvl[4] = "HALALMOD";
	ptr[4] = &Harl::halalmod;
}

Harl::~Harl(void){}

t_level	Harl::get_level(std::string level)
{
	int	i = 0;

	while (i <= HALALMOD && level != lvl[i])
		i++;
	return ((t_level)i);
}

void Harl::complain(std::string level)
{
	int	count = get_level(level);

	for (int i(0); i <= count ; i++)
	{
		if (level == lvl[i])
			(this->*ptr[i])();
	}
}

void Harl::debug(void)
{
	std::cout << "I love having extra halal bacon for my halal ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger.";
	std::cout << " I really do !\n\n";
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra halal bacon costs more money.";
	std::cout << " You didn\'t put enough halal bacon in my halal burger ! ";
	std::cout << "If you did, I wouldn\'t be asking for more !\n\n";
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra halal bacon for free. ";
	std::cout << "I\'ve been coming for years whereas you started ";
	std::cout << "working here since last month.\n\n";
}

void Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now.\n";
}

void Harl::halalmod(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]\n";
}
