/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:27:41 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/15 20:39:47 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

static Base	*generate(void)
{
	std::srand(time(NULL));
	switch (std::rand() % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return (NULL);
}

static void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C\n";
	else
		std::cout << "NULL\n";
}

static void	identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A\n";
	}
	catch (std::exception &exception)
	{
		try
		{
			B	&b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B\n";
		}
		catch (std::exception &exception)
		{
			try
			{
				C	&c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C\n";
			}
			catch (std::exception &exception)
			{
				std::cout << "NULL\n";
			}
		}
	}
}

int	main(void)
{
	Base	*base = generate();
	Base	&ref = *base;

	std::cout << "base : ";
	identify(base);

	std::cout << "ref : ";
	identify(ref);
	
	return (delete base, 0);
}
