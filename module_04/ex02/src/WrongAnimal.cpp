/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:41:31 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/25 16:01:19 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <WrongAnimal.hpp>

WrongAnimal::WrongAnimal(void) : type("Unknown")
{
	std::cout << "WrongAnimal->" << type << " : Default constructor called\n";
}

WrongAnimal::WrongAnimal(std::string new_type) : type(new_type)
{
	std::cout << "WrongAnimal->" << type << " : Constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal)
{
	std::cout << "WrongAnimal->" << type << " : Copy constructor called\n";
	*this = wronganimal;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &wronganimal)
{
	std::cout << "WrongAnimal->" << type << " : Copy assignment operator called\n";
	type = wronganimal.type;

	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal->" << type << " : Default destructor called\n";
}

std::string	WrongAnimal::getType(void)
{
	return (type);
}

void	WrongAnimal::makeSound(void)const
{
	std::cout << "Animal->" << type << " : HAWEW\n";
}
