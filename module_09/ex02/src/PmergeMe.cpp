/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:57:45 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/04/01 19:54:54 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : error(false)
{
	// std::cout << "Default constructor called !\n";
}

PmergeMe::PmergeMe(char **arg) : error(false)
{
	// std::cout << "Constructor called !\n";
	init(arg);
	if (error == false)
	{
		exec(vec, "vector", true);
		exec(lst, "list", false);
	}
}

PmergeMe::PmergeMe(const PmergeMe &pgm)
{
	// std::cout << "Copy constructor called !\n";
	*this = pgm;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &pgm)
{
	// std::cout << "Copy assignement operator called !\n";
	error = pgm.error;
	vec = pgm.vec;
	lst = pgm.lst;
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	// std::cout << "Destructor called !\n";
}

bool	PmergeMe::getError(void)const
{
	return (error);
}

std::vector<int>	PmergeMe::getVec(void)const
{
	return (vec);
}

std::list<int>	PmergeMe::getLst(void)const
{
	return (lst);
}

void	PmergeMe::addNumber(char *str, int i)
{
	long	nb = 0;

	if (std::isdigit(str[i]) && (!i || (i > 0 && std::isspace(str[i - 1]))))
	{
		nb = std::atol(&str[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error = true;
		else
		{
			vec.push_back(nb);
			lst.push_back(nb);
		}
	}
}

void	PmergeMe::init(char **arg)
{
	int		count;

	for (int i(0); arg[i] && error == false; i++)
	{
		count = 0;
		for (int j(0); arg[i][j] && error == false; j++)
		{
			if (std::isdigit(arg[i][j]))
				count++;
			else
				count = 0;
			if ((!std::isdigit(arg[i][j]) && !std::isspace(arg[i][j])) || count > 10)
				error = true;
			else
				addNumber(arg[i], j);
		}
	}
	error = parse();
}

bool	PmergeMe::parse(void)
{
	if (error == true || vec.size() < 2)
		return (true);
	std::vector<int>::const_iterator	it = vec.begin() + 1;
	std::vector<int>::const_iterator	end = vec.end();
	int									tmp = *(vec.begin());

	error = true;
	while (it != end)
	{
		if (tmp > *it)
			error = false;
		if (std::find(it, end, tmp) != end)
			return (true);
		tmp = *it;
		it++;
	}
	return (error);
}

template <typename T>
void	PmergeMe::print(T it, T end)
{
	while (it != end)
		std::cout << *(it++) << ' ';
	std::cout << std::endl;
}

template <typename T, typename U>
void PmergeMe::insert(U begin, U end)
{
	for (U it = std::next(begin); it != end; it++)
	{
		auto tmp = it;
		auto val = *it;
		while (tmp != begin && val < *std::prev(tmp))
		{
			*(tmp) = *std::prev(tmp);
			tmp--;
		}
		*tmp = val;
	}
}

template <typename T, typename U>
void	PmergeMe::sort(T &container, U begin, U end)
{
	size_t	size = std::distance(begin, end);

	if (size <= 1)
		return ;
	if (size <= 42)
	{
		insert<T, U>(begin, end);
		return ;
	}

	U mid = std::next(begin, size / 2);
	sort(container, begin, mid);
	sort(container, mid, end);

	T tmp(size);
	std::merge(begin, mid, mid, end, tmp.begin());
	std::copy(tmp.begin(), tmp.end(), begin);
}

template <typename T>
void	PmergeMe::exec(T &container, const char *name, bool display)
{
	if (display == true)
	{
		std::cout << "Before : ";
		print(container.begin(), container.end());
	}

	std::chrono::high_resolution_clock::time_point start;
	start = std::chrono::high_resolution_clock::now();
	sort(container, container.begin(), container.end());
	std::chrono::high_resolution_clock::time_point end;
	end = std::chrono::high_resolution_clock::now();

	if (display == true)
	{
		std::cout << "After : ";
		print(container.begin(), container.end());
	}

	std::chrono::duration<double, std::micro>	time = end - start;
	std::cout << "Time to process a range of " << container.size();
	std::cout << " elements with std::" << name << " : " << time.count() << " us\n";
}
