/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:44:53 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/24 20:07:32 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

/*---------------------------------C_ANIMAL----------------------------------*/

class Animal
{
	public:
						Animal(void);
						Animal(std::string new_type);
						Animal(const Animal &animal);
		Animal			&operator=(const Animal &animal);
		virtual			~Animal(void);

		std::string		getType(void)const;
		virtual void	makeSound(void)const = 0;

	protected:
		std::string		type;
};

/*------------------------------------T^T------------------------------------*/

#endif
