/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:18:19 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/28 21:41:54 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <AMateria.hpp>

class AMateria;

/*------------------------------I_MATERIASOURCE------------------------------*/

class IMateriaSource
{
	public:
		virtual				~IMateriaSource(void){}

		virtual void		learnMateria(AMateria *amatertia) = 0;
		virtual AMateria	*createMateria(const std::string &type) = 0;
};

/*------------------------------C_MATERIASOURCE------------------------------*/

class MateriaSource : public IMateriaSource
{
	public:
						MateriaSource(void);
						MateriaSource(const MateriaSource &msrc);
		MateriaSource	&operator=(const MateriaSource &msrc);
		virtual			~MateriaSource(void);

		void			learnMateria(AMateria *amateria);
		AMateria		*createMateria(const std::string &new_type);

	private:
		AMateria		*stock[4];
		int				idx;
};

/*------------------------------------T^T------------------------------------*/

#endif
