/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:41:24 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/28 21:41:18 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <Animal.hpp>
# include <Brain.hpp>

/*-----------------------------------C_DOG-----------------------------------*/

class Dog : public Animal
{
	public:
						Dog(void);
						Dog(const Dog &cat);
		Dog				&operator=(const Dog &cat);
		virtual			~Dog(void);

		virtual void	makeSound(void)const;

	private:
		Brain	*brain;
};

/*------------------------------------T^T------------------------------------*/

#endif
