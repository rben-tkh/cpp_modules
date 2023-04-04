/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 06:03:41 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/24 13:30:26 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <ClapTrap.hpp>

/*---------------------------------C_FRAGTRAP---------------------------------*/

class FragTrap : public ClapTrap
{
	public:
					FragTrap(void);
					FragTrap(std::string new_name);
					FragTrap(const FragTrap &fragtrap);
		FragTrap	&operator=(const FragTrap &fragtrap);
					~FragTrap(void);

		void		highFivesGuys(void);
};

/*------------------------------------T^T------------------------------------*/

#endif
