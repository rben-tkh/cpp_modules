/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:27:37 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/06 09:27:38 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

/*-----------------------------------C_BASE----------------------------------*/

class Base
{
	public:
		virtual	~Base(void);
};

/*------------------------------------C_A------------------------------------*/

class A : public Base
{};

/*------------------------------------C_B------------------------------------*/

class B : public Base
{};

/*------------------------------------C_C------------------------------------*/

class C : public Base
{};

/*------------------------------------T^T------------------------------------*/

#endif
