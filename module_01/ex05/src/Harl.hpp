/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:34:26 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/12/31 18:34:27 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

# include <iostream>
# include <string>

/*-----------------------------------C_HARL----------------------------------*/

class Harl
{
	public:
				Harl(void);
				~Harl(void);
		void	complain(std::string level);

	private:
		const char	*lvl[4];
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		typedef void(Harl::*pHarl)();
		pHarl ptr[4];
};

/*------------------------------------T^T------------------------------------*/

#endif