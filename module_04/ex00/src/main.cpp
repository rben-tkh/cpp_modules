/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:51:39 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/25 16:59:10 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>

int main(void)
{
	std::cout << "Creating Chi :\n\n";

	const Cat	usa_shortair;
	const Cat	chi(usa_shortair);

	std::cout << "\nCreating 3 animals :\n\n";

	const Animal	*cat = new Cat();
	const Animal	*dog = new Dog();
	const Animal	*unknown = new Animal();

	cat->makeSound();
	dog->makeSound();
	unknown->makeSound();

	std::cout << "\nDeleting 3 animals :\n\n";
	delete cat, delete dog, delete unknown;


	std::cout << "\nCreating 2 wrongs animals :\n\n";

	const WrongAnimal *wronganimal = new WrongAnimal();
	const WrongAnimal *wrongcat = new WrongCat();

	wrongcat->makeSound();
	wronganimal->makeSound();

	std::cout << "\nDeleting 2 wrongs animals :\n\n";
	delete wronganimal, delete wrongcat;
	
	std::cout << "\nDeleting Chi :\n\n";

	return (0);
}
