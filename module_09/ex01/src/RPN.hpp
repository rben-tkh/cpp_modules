/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:08:17 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/03/30 16:07:16 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstring>
# include <cstdlib>
# include <climits>
# include <algorithm>
# include <stack>

/*-----------------------------------C_RPN-----------------------------------*/

class RPN
{
	public:
							RPN(void);
							RPN(char *expression);
							RPN(const RPN &rpn);
		RPN					&operator=(const RPN &rpn);
							~RPN(void);

		bool				getError(void)const;
		std::stack<float>	getNb(void)const;

		bool				isop(char c);
		void				parse(char *str);
		void				exec(char *expression);

	private:
		bool				error;
		std::stack<float>	nb;
};

/*------------------------------------T^T------------------------------------*/

#endif
