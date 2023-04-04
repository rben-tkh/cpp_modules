/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:18:30 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/11 16:56:35 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

/*----------------------------------C_WEAPON---------------------------------*/

class Weapon
{
	public:
							Weapon(std::string type);
							Weapon(void);
							~Weapon(void);
		const std::string	&getType(void)const;
		void				setType(std::string new_type);

	private:
		std::string	type;
};

/*------------------------------------T^T------------------------------------*/

#endif
