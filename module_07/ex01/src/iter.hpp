/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:02:43 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/24 21:36:06 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# define ERROR -2147483649

# include <iostream>
# include <cstring>
# include <cstdlib>
# include <climits>

/*-----------------------------------T_ITER----------------------------------*/

template <typename T, typename F>
void	iter(T *tab, int size, F apply)
{
	for (int i(0); i < size; i++)
		apply(tab[i]);
}

/*----------------------------------T_PRINT----------------------------------*/

template <typename T>
void	print(T x)
{
	std::cout << x << std::endl;
}

/*-----------------------------------UTILS-----------------------------------*/

bool	check_input(char **av);
void	get_len(int *len, char **av);
long	ft_atol(char *str);

/*------------------------------------T^T------------------------------------*/

#endif
