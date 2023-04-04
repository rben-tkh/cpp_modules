/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:05:28 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/25 16:00:31 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Animal.hpp>

Animal::Animal(void) : type("Unknown")
{
	std::cout << "Animal->" << type << " : Default constructor called\n";
}

Animal::Animal(std::string new_type) : type(new_type)
{
	std::cout << "Animal->" << type << " : Constructor called\n";
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal->" << type << " : Copy constructor called\n";
	*this = animal;
}

Animal	&Animal::operator=(const Animal &animal)
{
	std::cout << "Animal->" << type << " : Copy assignment operator called\n";
	type = animal.type;

	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal->" << type << " : Default destructor called\n";
}

std::string	Animal::getType(void)const
{
	return (type);
}

void	Animal::makeSound(void)const
{
	std::cout << "Animal->" << type << " : HEWAW\n";
}
