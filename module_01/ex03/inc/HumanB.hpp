/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:18:27 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/11 17:02:12 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

/*----------------------------------C_HUMANB---------------------------------*/

class HumanB
{
	public:
				HumanB(std::string name);
				~HumanB(void);
		void	setWeapon(Weapon &new_weapon);
		void	attack(void)const;

	private:
		std::string	name;
		Weapon		*weapon;
};

/*------------------------------------T^T------------------------------------*/

#endif
