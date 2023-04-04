/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:18:01 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/12/30 18:18:02 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string new_name, Weapon &new_weapon)
			: name(new_name), weapon(new_weapon){}

HumanA::~HumanA(void){}

void	HumanA::attack(void)const
{
	std::cout << name << " attacks with their ";
	std::cout << weapon.getType() << std::endl;
}
