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

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap superman("Superman");
	ClapTrap batman("Batman");
	ClapTrap thanos("Thanos");

	thanos.attack("the world");
	superman.takeDamage(8);
	batman.takeDamage(10);
	superman.beRepaired(2);
	batman.beRepaired(10);
	thanos.attack("Superman");
	superman.takeDamage(6);
	thanos.attack("Superman");
	superman.takeDamage(1);

	ClapTrap unknown;
	unknown.attack("Thanos");
	thanos.takeDamage(10);
	thanos.attack("Unknown");
	return (0);
}
