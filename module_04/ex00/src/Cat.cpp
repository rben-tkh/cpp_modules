/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:41:29 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/25 16:01:59 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cat.hpp>

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat : Default constructor called\n";
}

Cat::Cat(const Cat &cat) : Animal("Cat")
{
	std::cout << "Cat : Copy constructor called\n";
	*this = cat;
}

Cat	&Cat::operator=(const Cat &cat)
{
	std::cout << "Cat : Copy assignment operator called\n";
	type = cat.type;

	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat : Default destructor called\n";
}

void	Cat::makeSound(void)const
{
	std::cout << "Cat : MIAW\n";
}
