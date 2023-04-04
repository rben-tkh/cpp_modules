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

#include <ScavTrap.hpp>

int main(void)
{
	ClapTrap batman("Batman");
	ScavTrap superman("Superman");
	ScavTrap thanos("Thanos");

	for (int i(0); i < 10; i++)
		batman.attack("Thanos");
	batman.attack("Thanos");
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

	ScavTrap unknown;
	unknown.guardGate();
	unknown.attack("Thanos");
	thanos.takeDamage(999);
	thanos.attack("Unknown");
	return (0);
}
