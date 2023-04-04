/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 05:39:48 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/12/30 05:39:49 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

/*---------------------------------C_CONTACT---------------------------------*/

class	Contact
{
	public:
		Contact	add_pal(void);
		int		display_book(int j, Contact pal);
		void	display_pal(int j, Contact pal);

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

/*----------------------------------PARSING----------------------------------*/

std::string	check_input(std::string input, std::string info, int val);

/*------------------------------------T^T------------------------------------*/

#endif