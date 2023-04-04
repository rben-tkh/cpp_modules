/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 07:01:58 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/21 07:01:59 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <DiamondTrap.hpp>

int main(void)
{
	ClapTrap batman("Batman");
	FragTrap superman("Superman");
	ScavTrap thanos("Thanos");

	for (int i(0); i < 10; i++)
		batman.attack("Thanos");
	batman.attack("Thanos");
	superman.highFivesGuys();
	thanos.takeDamage(10);
	thanos.attack("the world");
	batman.takeDamage(99);
	superman.takeDamage(99);
	superman.beRepaired(98);
	superman.attack("Thanos");
	thanos.takeDamage(20);
	thanos.attack("Superman");
	superman.takeDamage(99);
	superman.beRepaired(1);

	DiamondTrap unknown;

	unknown.whoAmI();
	thanos.attack("Unknown");
	unknown.takeDamage(0);
	thanos.guardGate();
	thanos.attack("Unknown");
	unknown.takeDamage(1);
	unknown.attack("Thanos");
	thanos.takeDamage(999);
	superman.highFivesGuys();
	thanos.attack("Unknown");
	return (0);
}
