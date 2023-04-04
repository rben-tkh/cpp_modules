/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:41:20 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/28 21:40:41 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <Animal.hpp>

/*-----------------------------------C_CAT-----------------------------------*/

class Cat : public Animal
{
	public:
				Cat(void);
				Cat(const Cat &cat);
		Cat		&operator=(const Cat &cat);
		virtual	~Cat(void);

		virtual void	makeSound(void)const;
};

/*------------------------------------T^T------------------------------------*/

#endif
