/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:03 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/12/30 15:08:04 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	bizon;
	bizon.setname("Jean");

	Zombie	*bizonPtr;
	bizonPtr = newZombie("Claude");

	bizon.announce();
	bizonPtr[0].announce();

	randomChump("François");

	delete (bizonPtr);

	randomChump("Lebonhomme");

	return (0);
}
