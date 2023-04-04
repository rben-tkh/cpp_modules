/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:11:19 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/28 19:34:51 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Ice.hpp>

Ice::Ice(void) : AMateria("ice")
{
	// std::cout << "Default constructor called\n";
}

Ice::Ice(const Ice &ice) : AMateria("ice")
{
	// std::cout << "Copy constructor called\n";
	*this = ice;
}

Ice	&Ice::operator=(const Ice &ice)
{
	// std::cout << "Copy assignement operator called\n";
	(void)ice;
	
	return (*this);
}

Ice::~Ice(void)
{
	// std::cout << "Default destructor called\n";
}

AMateria	*Ice::clone(void)const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
