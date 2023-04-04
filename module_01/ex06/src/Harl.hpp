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

/*----------------------------------E_LEVEL----------------------------------*/

typedef enum e_level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	HALALMOD,
}	t_level;

/*-----------------------------------C_HARL----------------------------------*/

class Harl
{
	public:
				Harl(void);
				~Harl(void);
		void	complain(std::string level);
		t_level	get_level(std::string level);

	private:
		const char	*lvl[5];
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	halalmod(void);
		typedef void(Harl::*pHarl)();
		pHarl ptr[5];
};

/*------------------------------------T^T------------------------------------*/

#endif
