/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:18:05 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/11 17:02:42 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string new_name) : name(new_name){}

HumanB::~HumanB(void){}

void	HumanB::setWeapon(Weapon &new_weapon){weapon = &new_weapon;}

void	HumanB::attack(void)const
{
	std::cout << name << " attacks with their ";
	std::cout << weapon[0].getType() << std::endl;
}
