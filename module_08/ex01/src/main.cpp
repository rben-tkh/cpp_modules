/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:00:12 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/03/12 18:00:13 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

std::ostream	&operator<<(std::ostream &out, const Span &span)
{
    out << "[ ";
    for (std::vector<int>::const_iterator it = span.getVec().begin(); it != span.getVec().end(); it++)
    {
        out << *it << ' ';
    }
    out << ']';

    return (out);
}

int main (void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp << std::endl;
	std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest : " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
	
	try
	{
		sp.addNumber(42);
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	Span sp2(sp);

	sp2.addMutipleNumber(sp.getVec().begin(), sp.getVec().end());
	std::cout << sp << std::endl;
	std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest : " << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	Span sp3(1);

	try
	{
		sp3.addNumber(42);
		std::cout << "Shortest : " << sp3.shortestSpan() << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}
	try
	{
		std::cout << "Longest : " << sp3.longestSpan() << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	return (0);
}
