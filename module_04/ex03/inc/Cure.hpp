/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:11:15 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/28 21:41:48 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <AMateria.hpp>

class AMateria;

/*-----------------------------------C_CURE----------------------------------*/

class Cure : public AMateria
{
	public:
					Cure(void);
					Cure(const Cure &cure);
		Cure		&operator=(const Cure &cure);
		virtual		~Cure(void);

		AMateria	*clone(void)const;
		void		use(ICharacter &target);
};

/*------------------------------------T^T------------------------------------*/

#endif
