/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:52:56 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/30 17:21:05 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AMateria.hpp>
#include <Cure.hpp>
#include <Ice.hpp>
#include <MateriaSource.hpp>

int	main(void)
{
	IMateriaSource	*src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter	*me = new Character("me");
	ICharacter	*you = new Character("you");

	*you = *me;

	AMateria	*tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	you->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);
	you->equip(tmp);

	me->equip(src->createMateria("test"));

	ICharacter	*bob = new Character("bob");

	you->use(0, *me);
	me->use(0, *you);
	me->unequip(0);
	you->use(0, *me);
	me->use(0, *bob);

	me->use(1, *bob);
	me->use(9, *bob);

	bob->use(0, *me);

	delete bob, delete me, delete you, delete src;

	return (0);
}
