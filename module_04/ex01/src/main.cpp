/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:51:39 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/25 16:55:47 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Brain.hpp>
#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>

int main(void)
{
	std::cout << "Creating Scooby-Doo :\n\n";

	const Dog	german_dogue;
	const Dog	scooby_doo(german_dogue);

	const Animal	*tab[10];

	std::cout << "\nCreating 5 cats :\n\n";

	for (int k(0); k < 5; k++)
		tab[k] = new Cat();

	std::cout << "\nCreating 5 dogs :\n\n";

	for (int k(5); k < 10; k++)
		tab[k] = new Dog();

	std::cout << "\nDeleting all :\n\n";

	for (int k(0); k < 10; k++)
		delete tab[k];

	std::cout << "\nDeleting Scooby-Doo :\n\n";

	return (0);
}
