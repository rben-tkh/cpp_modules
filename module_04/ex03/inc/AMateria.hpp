/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:54:58 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/27 19:29:25 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <Character.hpp>
# include <MateriaSource.hpp>

class ICharacter;

/*--------------------------------C_AMATERIA---------------------------------*/

class AMateria
{
	public:
							AMateria(std::string const &new_type);
							AMateria(const AMateria &amateria);
		AMateria			&operator=(const AMateria &amateria);
		virtual				~AMateria(void);

		std::string const	&getType(void)const;
		virtual AMateria	*clone(void)const = 0;
		virtual void		use(ICharacter &target);

	protected:
		std::string			type;
};

/*------------------------------------T^T------------------------------------*/

#endif
