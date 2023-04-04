/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:08:33 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/24 13:31:14 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <ClapTrap.hpp>

/*---------------------------------C_SCAVTRAP---------------------------------*/

class ScavTrap : virtual public ClapTrap
{
	public:
					ScavTrap(void);
					ScavTrap(std::string new_name);
					ScavTrap(const ScavTrap &scavtrap);
		ScavTrap	&operator=(const ScavTrap &scavtrap);
					~ScavTrap(void);

		void		attack(const std::string &target);
		void		guardGate(void);
};

/*------------------------------------T^T------------------------------------*/

#endif
