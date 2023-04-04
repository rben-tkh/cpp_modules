/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:15:38 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/03/20 17:09:29 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "mstack :\n";
	print(it, ite);

	//std::stack<int> s(mstack); impossible because
	//print(s.begin(), s.end()); stack is not iterable

	MutantStack<int> reverse(mstack);
	MutantStack<int>::reverse_iterator rit = reverse.rbegin();
	MutantStack<int>::reverse_iterator rite = reverse.rend();
	std::cout << "\nreverse copy of mstack :\n";
	print(rit, rite);

	return (0);
}
