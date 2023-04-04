/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:41:38 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/24 13:27:59 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

/*----------------------------------C_FIXED----------------------------------*/

class Fixed
{
	public:
				Fixed(void);
				Fixed(const Fixed &fix);
		Fixed	&operator=(const Fixed &fix);
				~Fixed(void);

		int	getRawBits(void)const;
		void setRawBits(int const raw);

	private:
		int					val;
		static const int	nb_bits = 8;
};

/*------------------------------------T^T------------------------------------*/

#endif