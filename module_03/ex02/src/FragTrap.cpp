/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 06:03:50 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/24 13:40:27 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <FragTrap.hpp>

FragTrap::FragTrap(void) : ClapTrap()
{
	hit = 100, energy = 100, damage = 30;
	std::cout << "FragTrap : " << name << " join the party !\n";
}

FragTrap::FragTrap(std::string new_name) : ClapTrap(new_name)
{
	hit = 100, energy = 100, damage = 30;
	std::cout << "FragTrap : " << name << " join the party !\n";
}

FragTrap::FragTrap(const FragTrap &fragtrap) : ClapTrap(fragtrap)
{
	*this = fragtrap;
	std::cout << "FragTrap : " << name << " join the party !\n";
}

FragTrap	&FragTrap::operator=(const FragTrap &fragtrap)
{
	name = fragtrap.name;
	hit = fragtrap.hit;
	energy = fragtrap.energy;
	damage = fragtrap.damage;
	std::cout << "FragTrap : " << name << " join the party !\n";

	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap : " << name << " left the party !\n";
}

void	FragTrap::highFivesGuys(void)
{
	if (!hit)
	{
		std::cout << "FragTrap : " << name << " feels alone in his grave !\n";
		return ;
	}
	std::cout << "FragTrap : " << name << " wants to make a high fives !\n";
}
