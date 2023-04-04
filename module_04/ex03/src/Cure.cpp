/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:11:12 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/28 19:34:35 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cure.hpp>

Cure::Cure(void) : AMateria("cure")
{
	// std::cout << "Default constructor called\n";
}

Cure::Cure(const Cure &cure) : AMateria("cure")
{
	// std::cout << "Copy constructor called\n";
	*this = cure;
}

Cure	&Cure::operator=(const Cure &cure)
{
	// std::cout << "Copy assignement operator called\n";
	(void)cure;

	return (*this);
}

Cure::~Cure(void)
{
	// std::cout << "Default destructor called\n";
}

AMateria	*Cure::clone(void)const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *\n";
}
