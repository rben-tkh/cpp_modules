/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:41:27 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/24 19:26:12 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <WrongAnimal.hpp>

/*-----------------------------------C_CAT-----------------------------------*/

class WrongCat : public WrongAnimal
{
	public:
					WrongCat(void);
					WrongCat(const WrongCat &wrongcat);
		WrongCat	&operator=(const WrongCat &wrongcat);
		virtual		~WrongCat(void);

		void		makeSound(void);
};

/*------------------------------------T^T------------------------------------*/

#endif
