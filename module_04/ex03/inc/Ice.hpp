/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:11:22 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/28 21:41:51 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <AMateria.hpp>

class AMateria;

/*-----------------------------------C_ICE-----------------------------------*/

class Ice : public AMateria
{
	public:
					Ice(void);
					Ice(const Ice &ice);
		Ice			&operator=(const Ice &ice);
		virtual		~Ice(void);

		AMateria	*clone(void)const;
		void		use(ICharacter &target);
};

/*------------------------------------T^T------------------------------------*/

#endif
