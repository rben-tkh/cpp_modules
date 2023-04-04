/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:41:29 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/25 16:52:12 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cat.hpp>

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat : Default constructor called\n";
	brain = new Brain;
}

Cat::Cat(const Cat &cat) : Animal("Cat")
{
	std::cout << "Cat : Copy constructor called\n";
	brain = new Brain(*cat.brain);
}

Cat	&Cat::operator=(const Cat &cat)
{
	std::cout << "Cat : Copy assignment operator called\n";
	type = cat.type;
	delete brain;
	brain = new Brain(*cat.brain);

	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat : Default destructor called\n";
	delete brain;
}

void	Cat::makeSound(void)const
{
	std::cout << "Cat : MIAW\n";
}
