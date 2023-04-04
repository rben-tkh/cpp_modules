/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:15:41 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/03/20 16:43:56 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <deque>

/*------------------------------CT_MUTANTSTACK-------------------------------*/

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void)
		{
			// std::cout << "Default constructor called !\n";
		}
		MutantStack(const MutantStack<T> &ms)
		{
			// std::cout << "Copy constructor called !\n";
			this->c = ms.c;
		}
		MutantStack<T>	&operator=(const MutantStack<T> &ms)
		{
			// std::cout << "Copy assignement operator called !\n";
			this->c = ms.c;
			return (*this);
		}
		virtual	~MutantStack(void)
		{
			// std::cout << "Destructor called !\n";
		}

		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

		iterator	begin(void) 
		{
			return (this->c.begin());
		}
		iterator	end(void)
		{
			return (this->c.end());
		}

		const_iterator	cbegin(void) 
		{
			return (this->c.cbegin());
		}
		const_iterator	cend(void)
		{
			return (this->c.cend());
		}

		reverse_iterator	rbegin(void) 
		{
			return (this->c.rbegin());
		}
		reverse_iterator	rend(void)
		{
			return (this->c.rend());
		}

		const_reverse_iterator	crbegin(void) 
		{
			return (this->c.crbegin());
		}
		const_reverse_iterator	crend(void)
		{
			return (this->c.crend());
		}

};

/*----------------------------------T_PRINT-----------------------------------*/

template <typename T, typename E>
void	print(T it, E end)
{
	while (it != end)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

/*------------------------------------T^T------------------------------------*/

#endif
