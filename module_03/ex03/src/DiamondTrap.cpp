/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 07:45:46 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/22 07:45:47 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <DiamondTrap.hpp>

DiamondTrap::DiamondTrap(void)
					: ClapTrap(), ScavTrap(), FragTrap()
{
	name = "Unknown";
	hit = FragTrap::hit;
	energy = ScavTrap::energy;
	damage = FragTrap::damage;
	ClapTrap::name = name + "_clap_name";
	std::cout << "DiamondTrap : " << name << " join the party !\n";
}

DiamondTrap::DiamondTrap(std::string new_name)
					: ClapTrap(new_name), ScavTrap(new_name), FragTrap(new_name)
{
	name = new_name;
	hit = FragTrap::hit;
	energy = ScavTrap::energy;
	damage = FragTrap::damage;
	ClapTrap::name = name + "_clap_name";
	std::cout << "DiamondTrap : " << name << " join the party !\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap)
					: ClapTrap(diamondtrap), ScavTrap(diamondtrap), FragTrap(diamondtrap)
{
	name = diamondtrap.name;
	hit = diamondtrap.hit;
	energy = diamondtrap.energy;
	damage = diamondtrap.damage;
	ClapTrap::name = name + "_clap_name";
	std::cout << "DiamondTrap : " << name << " join the party !\n";
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
	name = diamondtrap.name;
	hit = diamondtrap.hit;
	energy = diamondtrap.energy;
	damage = diamondtrap.damage;
	ClapTrap::name = name + "_clap_name";

	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap : " << name << " left the party !\n";
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	if (!hit)
	{
		std::cout << "DiamondTrap : " << name << "would have liked to ";
		std::cout << "introduce himself but he died !";
	}
	std::cout << "DiamondTrap : " << "Hi. I'm " << name;
	std::cout << " and my ClapTrap's name is " << ClapTrap::name;
	std::cout << " what's going on ?\n";
}
