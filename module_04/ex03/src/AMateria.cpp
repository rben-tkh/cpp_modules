/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:54:55 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/27 18:39:12 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AMateria.hpp>

AMateria::AMateria(std::string const &new_type) : type(new_type)
{
	// std::cout << "Default constructor called\n";
}

AMateria::AMateria(const AMateria &AMateria)
{
	// std::cout << "Copy constructor called\n";
	*this = AMateria;
}

AMateria	&AMateria::operator=(const AMateria &AMateria)
{
	// std::cout << "Copy assignement operator called\n";
	type = AMateria.type;

	return (*this);
}

AMateria::~AMateria(void)
{
	// std::cout << "Default destructor called\n";
}

std::string const	&AMateria::getType(void)const
{
	return (type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
}
