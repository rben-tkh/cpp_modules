/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:41:38 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/01/24 13:28:15 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

/*----------------------------------C_FIXED----------------------------------*/

class Fixed
{
	public:
				Fixed(void);
				Fixed(const Fixed &fix);
				Fixed(const int new_val);
				Fixed(const float new_val);
		Fixed	&operator=(const Fixed &fix);
				~Fixed(void);

		int		getRawBits(void)const;
		void	setRawBits(int const raw);
		float	toFloat(void)const;
		int		toInt(void)const;

	private:
		int					val;
		static const int	nb_bits = 8;
};

/*----------------------------------OPERATOR---------------------------------*/

std::ostream	&operator<<(std::ostream &out, const Fixed &fix);

/*------------------------------------T^T------------------------------------*/

#endif
