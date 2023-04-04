/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:00:16 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/03/17 20:17:50 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : max(0), vec(0)
{
	// std::cout << "Default constructor called !\n";
}

Span::Span(unsigned int new_nb) : max(new_nb), vec(0)
{
	// std::cout << "Constructor called !\n";
}

Span::Span(const Span &span)
{
	// std::cout << "Copy constructor called !\n";
	*this = span;
}

Span	&Span::operator=(const Span &span)
{
	// std::cout << "Copy assignement operator called !\n";
	max = span.max;
	vec = span.vec;
	return (*this);
}

Span::~Span(void)
{
	// std::cout << "Destructor called !\n";
}

const std::vector<int>	&Span::getVec(void)const
{
	return (vec);
}

unsigned int	Span::getMax(void)const
{
	return (max);
}


void	Span::addNumber(int nb)
{
	if (vec.size() >= max)
		throw SpanFull();
	vec.push_back(nb);
}

void	Span::addMutipleNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	vec.insert(vec.begin(), begin, end);
	if (vec.size() >= max)
		vec.resize(max);
}

int	Span::shortestSpan(void)
{
	if (vec.size() < 2)
		throw DistanceNotFind();
	Span	tmp(*this);
	std::sort(tmp.vec.begin(), tmp.vec.end());
	int	last = tmp.vec.front();
	int	shortest = longestSpan();
	for (std::vector<int>::const_iterator	it = (tmp.vec.begin() + 1); it != tmp.vec.end(); it++)
	{
		if (*it - last < shortest)
			shortest = *it - last;
		last = *it;
	}
	return (shortest);
}

int	Span::longestSpan(void)
{
	if (vec.size() < 2)
		throw DistanceNotFind();	
	Span	tmp(*this);
	std::sort(tmp.vec.begin(), tmp.vec.end());
	return (tmp.vec.back() - tmp.vec.front());
}

const char	*Span::SpanFull::what(void)const throw()
{
	return ("The span is full !\n");
}

const char	*Span::DistanceNotFind::what(void)const throw()
{
	return ("Impossible to find the distance !\n");
}
