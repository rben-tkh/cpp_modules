/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:01:08 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/12/30 17:01:09 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*bizon = new Zombie[N];

	for (int i(0); i < N; i++)
	{
		bizon[i].setname(name);
		bizon[i].announce();
	}
	return (bizon);
}
