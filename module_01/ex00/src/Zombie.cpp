/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:20 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/12/30 15:08:21 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void){}

Zombie::~Zombie(void)
{
	std::cout << name << ": ...ZzzznnniiiiiiiarB\n";
}

void	Zombie::setname(std::string new_name){name = new_name;}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
