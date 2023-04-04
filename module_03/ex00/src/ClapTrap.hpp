/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 07:02:59 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/24 13:29:50 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

/*---------------------------------C_CLAPTRAP---------------------------------*/

class ClapTrap
{
	public:
					ClapTrap(void);
					ClapTrap(std::string new_name);
					ClapTrap(const ClapTrap &claptrap);
		ClapTrap	&operator=(const ClapTrap &claptrap);
					~ClapTrap(void);

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	private:
		std::string			name;
		unsigned int		hit;
		unsigned int		energy;
		unsigned int		damage;
};

/*------------------------------------T^T------------------------------------*/

#endif
