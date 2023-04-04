/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:18:23 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/12/30 18:18:24 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

/*----------------------------------C_HUMANA---------------------------------*/

class HumanA
{
	public:
				HumanA(std::string name, Weapon &weapon);
				~HumanA(void);
		void	attack(void)const;

	private:
		std::string	name;
		Weapon		&weapon;
};

/*------------------------------------T^T------------------------------------*/

#endif
