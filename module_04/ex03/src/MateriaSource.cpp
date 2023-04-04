/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:18:14 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/30 17:29:59 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MateriaSource.hpp>
#include <Ice.hpp>
#include <Cure.hpp>

MateriaSource::MateriaSource(void) : idx(0)
{
	// std::cout << "Default constructor called\n";
	for (int i(0); i < 4; i++)
		stock[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &msrc)
{
	// std::cout << "Copy constructor called\n";
	for (int i(0); i < 4 && msrc.stock[i] != NULL; i++)
		stock[i] = msrc.stock[i]->clone();
	idx = msrc.idx;
}

MateriaSource	&MateriaSource::MateriaSource::operator=(const MateriaSource &msrc)
{
	// std::cout << "Copy assignement operator called\n";
	for (int i(0); i < 4; i++)
	{
		delete stock[i];
		stock[i] = NULL;
	}
	for (int i(0); i < 4 && msrc.stock[i] != NULL; i++)
		stock[i] = msrc.stock[i]->clone();
	idx = msrc.idx;

	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	// std::cout << "Default destructor called\n";
	for (int i(0); i < 4; i++)
	{
		delete stock[i];
		stock[i] = NULL;
	}
}

void	MateriaSource::learnMateria(AMateria *amateria)
{
	if (amateria == NULL)
		return ;
	if (idx == 4)
	{
		delete amateria;
		amateria = NULL;
		return ;
	}
	stock[idx] = amateria;
	idx++;
}

AMateria	*MateriaSource::createMateria(const std::string &new_type)
{
	for (int i(0); i < 4 && stock[i] != NULL; i++)
	{
		if (stock[i]->getType() == new_type)
			return (stock[i]);
	}
	return (0);
}
