/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:41:30 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/25 16:52:10 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Dog.hpp>

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog : Default constructor called\n";
	brain = new Brain;
}

Dog::Dog(const Dog &dog) : Animal("Dog")
{
	std::cout << "Dog : Copy constructor called\n";
	brain = new Brain(*dog.brain);
}

Dog	&Dog::operator=(const Dog &dog)
{
	std::cout << "Dog : Copy assignment operator called\n";
	type = dog.type;
	delete brain;
	brain = new Brain(*dog.brain);

	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog : Default destructor called\n";
	delete brain;
}

void	Dog::makeSound(void)const
{
	std::cout << "Dog : WUF\n";
}
