/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 07:45:35 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/24 13:31:03 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <ScavTrap.hpp>
# include <FragTrap.hpp>

/*-------------------------------C_DIAMONDTRAP-------------------------------*/

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
					DiamondTrap(void);
					DiamondTrap(std::string new_name);
					DiamondTrap(const DiamondTrap &diamondtrap);
		DiamondTrap	&operator=(const DiamondTrap &diamondtrap);
					~DiamondTrap(void);

		void		attack(const std::string &target);
		void		whoAmI(void);

	private:
		std::string	name;
};

/*------------------------------------T^T------------------------------------*/

#endif
