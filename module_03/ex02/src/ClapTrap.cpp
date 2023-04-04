/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 07:01:36 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/21 07:01:37 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>

ClapTrap::ClapTrap(void)
				: name("Unknown"), hit(10), energy(10), damage(0)
{
	std::cout << "ClapTrap : " << name << " join the party !\n";
}

ClapTrap::ClapTrap(std::string new_name)
				: name(new_name), hit(10), energy(10), damage(0)
{
	std::cout << "ClapTrap : " << new_name << " join the party !\n";
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	*this = claptrap;
	std::cout << "ClapTrap : " << name << " join the party !\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	name = claptrap.name;
	hit = claptrap.hit;
	energy = claptrap.energy;
	damage = claptrap.damage;
	std::cout << "ClapTrap : " << name << " join the party !\n";

	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap : " << name << " left the party !\n";
}

void	ClapTrap::attack(const std::string &target)
{
	if (!hit)
	{
		std::cout << "ClapTrap : " << name << " would like ";
		std::cout << "to attack " << target << " with his soul"; 
		std::cout << " but it doesn't work !\n";
		return ;
	}
	else if (!energy)
	{
		std::cout << "ClapTrap : " << name << " would like ";
		std::cout << "to attack " << target << " but he has no more energy !\n";
		return ;
	}
	std::cout << "ClapTrap : " << name << " attacks " << target << " !\n";
	energy -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!hit)
	{
		std::cout << "ClapTrap : " << name << " can't ";
		std::cout << "take anymore damage because he is dead !\n";
		return ;
	}
	std::cout << "ClapTrap : " << name << " take " << amount;
	std::cout << " points of damage !\n";
	if (amount >= hit)
	{
		hit = 0;
		std::cout << "ClapTrap : " << name << " died !\n";
	}
	else
		hit -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!hit)
	{
		std::cout << "ClapTrap : " << name << " would like ";
		std::cout << "to repair itself from its grave but it doesn't work !\n";
		return ;
	}
	else if (!energy)
	{
		std::cout << "ClapTrap : " << name << " would like ";
		std::cout << "to repair itself but he has no more energy !\n";
		return ;
	}
	std::cout << "ClapTrap : " << name << " repairs itself, gain ";
	std::cout << amount << " hits points and goes back to ";
	std::cout << (hit + amount) << " hits points !\n";
	hit += amount;
	energy -= 1;
}
