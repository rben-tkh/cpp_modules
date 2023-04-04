/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:38:41 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/25 16:00:56 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Brain.hpp>

Brain::Brain(void)
{
	std::cout << "Brain : Default constructor called\n";
	for (int i(0); i < 100; i++)
		ideas[i] = "EAT";
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain : Copy constructor called\n";
	*this = brain;
}

Brain	&Brain::operator=(const Brain &brain)
{
	std::cout << "Brain : Copy assignment operator called\n";
	for (int i(0); i < 100; i++)
		ideas[i] = brain.ideas[i];

	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain : Default destructor called\n";
}
