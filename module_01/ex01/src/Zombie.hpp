/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:27 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/12/30 15:08:27 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

/*----------------------------------C_ZOMBIE---------------------------------*/

class Zombie
{
	public:
					Zombie(void);
					~Zombie(void);
		void		setname(std::string new_name);
		void		announce(void);

	private:
		std::string	name;
};

/*-----------------------------------ZOMBIE----------------------------------*/

Zombie	*zombieHorde(int N, std::string name);

/*------------------------------------T^T------------------------------------*/

#endif
