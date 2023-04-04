/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:41:33 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/24 20:36:07 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <WrongCat.hpp>

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat : Default constructor called\n";
}

WrongCat::WrongCat(const WrongCat &wrongcat) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat : Copy constructor called\n";
	*this = wrongcat;
}

WrongCat	&WrongCat::operator=(const WrongCat &wrongcat)
{
	std::cout << "WrongCat : Copy assignment operator called\n";
	type = wrongcat.type;

	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat : Default destructor called\n";
}

void	WrongCat::makeSound(void)
{
	std::cout << "WrongCat : WRONG MIAW\n";
}
