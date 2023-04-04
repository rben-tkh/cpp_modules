/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 06:56:54 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/03/12 06:56:54 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# define TO_FIND 42

# include <iostream>
# include <climits>
# include <algorithm>
# include <list>

/*---------------------------------T_EASYFIND--------------------------------*/

template <typename T>
bool	easyfind(T container, int val)
{
	if (std::find(container.begin(), container.end(), val) == container.end())
		return (false);
	return (true);
}

/*------------------------------------T^T------------------------------------*/

#endif
