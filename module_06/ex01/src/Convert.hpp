/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:36:18 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/05 11:36:19 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <climits>
# include <cmath>
# include <stdint.h>

/*-----------------------------------C_DATA----------------------------------*/

class Data
{
	public:
					Data(void);
					Data(double nb);
					Data(const Data &data);
		Data		&operator=(const Data &data);
					~Data(void);

		int			getError(void)const;
		char		getC(void)const;
		int			getI(void)const;
		float		getF(void)const;
		double		getD(void)const;

		char		toChar(double nb);
		int			toInt(double nb);
		float		toFloat(double nb);

	private:
		int		error;
		char	c;
		int		i;
		float	f;
		double	d;
};

/*------------------------------------T^T------------------------------------*/

#endif
