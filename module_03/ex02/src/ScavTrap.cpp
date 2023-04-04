/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:08:28 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/24 13:40:25 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScavTrap.hpp>

ScavTrap::ScavTrap(void) : ClapTrap()
{
	hit = 100, energy = 50, damage = 20;
	std::cout << "ScavTrap : " << name << " join the party !\n";
}

ScavTrap::ScavTrap(std::string new_name) : ClapTrap(new_name)
{
	hit = 100, energy = 50, damage = 20;
	std::cout << "ScavTrap : " << name << " join the party !\n";
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap)
{
	*this = scavtrap;
	std::cout << "ScavTrap : " << name << " join the party !\n";
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &scavtrap)
{
	name = scavtrap.name;
	hit = scavtrap.hit;
	energy = scavtrap.energy;
	damage = scavtrap.damage;
	std::cout << "ScavTrap : " << name << " join the party !\n";

	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap : " << name << " left the party !\n";
}

void	ScavTrap::attack(const std::string &target)
{
	if (!hit)
	{
		std::cout << "ScavTrap : " << name << " would like ";
		std::cout << "to attack " << target << " with his soul"; 
		std::cout << " but it doesn't work !\n";
		return ;
	}
	else if (!energy)
	{
		std::cout << "ScavTrap : " << name << " would like ";
		std::cout << "to attack " << target << " but he has no more energy !\n";
		return ;
	}
	std::cout << "ScavTrap : " << name << " attacks " << target << " !\n";
	energy -= 1;
}

void	ScavTrap::guardGate(void)
{
	if (!hit)
	{
		std::cout << "ScavTrap : " << name << " wants to go into ";
		std::cout << "Gate Keeper mode to become overpowered";
		std::cout << " but it doesn't work !\n";
		return ;
	}
	std::cout << "ScavTrap : " << name << " is now in Gate Keeper mode !\n";
}
