/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:38:40 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/24 21:11:06 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

/*----------------------------------C_BRAIN----------------------------------*/

class Brain
{
	public:
					Brain(void);
					Brain(const Brain &brain);
		Brain		&operator=(const Brain &brain);
					~Brain(void);

	private:
		std::string	ideas[100];
};

/*------------------------------------T^T------------------------------------*/

#endif