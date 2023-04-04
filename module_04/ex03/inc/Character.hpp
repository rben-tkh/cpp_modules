/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:13:15 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/28 21:41:45 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <AMateria.hpp>

class AMateria;

/*--------------------------------I_CHARACTER--------------------------------*/

class ICharacter
{
	public:
		virtual						~ICharacter(void){}

		virtual const std::string	&getName(void)const = 0;
		virtual void				equip(AMateria *amateria) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter &target) = 0;
};

/*--------------------------------C_CHARACTER--------------------------------*/

class Character : public ICharacter
{
	public:
							Character(void);
							Character(const std::string new_name);
							Character(const Character &character);
		Character			&operator=(const Character &character);
		virtual				~Character(void);

		const std::string	&getName(void)const;
		void				equip(AMateria *amateria);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

	private:
		std::string		name;
		AMateria		*materia[4];
		AMateria		*floor;
};

/*------------------------------------T^T------------------------------------*/

#endif
