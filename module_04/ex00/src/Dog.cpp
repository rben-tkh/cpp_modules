/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:41:30 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/24 20:08:52 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Dog.hpp>

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog : Default constructor called\n";
}

Dog::Dog(const Dog &dog) : Animal("Dog")
{
	std::cout << "Dog : Copy constructor called\n";
	*this = dog;
}

Dog	&Dog::operator=(const Dog &dog)
{
	std::cout << "Dog : Copy assignment operator called\n";
	type = dog.type;

	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog : Default destructor called\n";
}

void	Dog::makeSound(void)const
{
	std::cout << "Dog : WUF\n";
}
