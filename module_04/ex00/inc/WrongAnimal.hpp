/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:41:26 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/28 21:41:03 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

/*-------------------------------C_WRONGANIMAL-------------------------------*/

class WrongAnimal
{
	public:
					WrongAnimal(void);
					WrongAnimal(std::string new_type);
					WrongAnimal(const WrongAnimal &wronganimal);
		WrongAnimal	&operator=(const WrongAnimal &wronganimal);
		virtual		~WrongAnimal(void);

		std::string	getType(void);
		void		makeSound(void)const;

	protected:
		std::string	type;
};

/*------------------------------------T^T------------------------------------*/

#endif
