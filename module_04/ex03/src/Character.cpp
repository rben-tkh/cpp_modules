/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:13:11 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/30 17:36:25 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Character.hpp>

Character::Character(void) : ICharacter(), name("unknown"), floor(NULL)
{
	// std::cout << "Default constructor called\n";
	for (int i(0); i < 4; i++)
		materia[i] = NULL;
}

Character::Character(const std::string new_name) : ICharacter(), name(new_name), floor(NULL)
{
	// std::cout << "Default constructor called\n";
	for (int i(0); i < 4; i++)
		materia[i] = NULL;
}

Character::Character(const Character &character) : ICharacter(), name(character.name)
{
	// std::cout << "Copy constructor called\n";
	for (int i(0); i < 4 && character.materia[i] != NULL; i++)
		materia[i] = character.materia[i]->clone();
	if (character.floor)
		floor = character.floor->clone();
}

Character	&Character::operator=(const Character &character)
{
	// std::cout << "Copy assignement operator called\n";
	for (int i(0); i < 4; i++)
	{
		delete materia[i];
		materia[i] = NULL;
	}
	delete floor;
	name = character.name;
	for (int i(0); i < 4 && character.materia[i] != NULL; i++)
		materia[i] = character.materia[i]->clone();
	if (character.floor)
		floor = character.floor->clone();

	return (*this);
}

Character::~Character(void)
{
	// std::cout << "Default destructor called\n";
	for (int i(0); i < 4; i++)
	{
		delete materia[i];
		materia[i] = NULL;
	}
	delete floor;
	floor = NULL;
}

const std::string	&Character::getName(void)const
{
	return (name);
}

void	Character::equip(AMateria *amateria)
{
	int i = 0;

	if (amateria == NULL)
		return ;
	while (i < 4 && materia[i] != NULL)
		i++;
	if (i == 4)
	{
		delete amateria;
		amateria = NULL;
		return ;
	}
	materia[i] = amateria->clone();
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || materia[idx] == NULL)
		return ;
	delete floor;
	floor = materia[idx];
	materia[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || materia[idx] == NULL)
		return ;
	materia[idx]->use(target);
}
