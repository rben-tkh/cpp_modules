/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:36:57 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/12/29 16:36:57 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

Contact	Contact::add_pal(void)
{
	Contact	pal;

	std::cout << std::endl;
	while (pal.first_name.empty())
	{
		std::cout << "First name > ";
		if (!std::getline(std::cin, pal.first_name))
			return (pal);
		pal.first_name = check_input(pal.first_name, "First Name !\n\n", 0);
	}
	while (pal.last_name.empty())
	{
		std::cout << "Last name > ";
		if (!std::getline(std::cin, pal.last_name))
			return (pal);
		pal.last_name = check_input(pal.last_name, "Last Name !\n\n", 0);
	}
	while (pal.nickname.empty())
	{
		std::cout << "Nickname > ";
		if (!std::getline(std::cin, pal.nickname))
			return (pal);
		pal.nickname = check_input(pal.nickname, "Nickname !\n\n", 2);
	}
	while (pal.phone_number.empty())
	{
		std::cout << "Phone Number > ";
		if (!std::getline(std::cin, pal.phone_number))
			return (pal);
		pal.phone_number = check_input(pal.phone_number, "Phone number !\n\n", 1);
	}
	while (pal.darkest_secret.empty())
	{
		std::cout << "Darkest Secret > ";
		if (!std::getline(std::cin, pal.darkest_secret))
			return (pal);
		pal.darkest_secret = check_input(pal.darkest_secret, "Darkest Secret !\n\n", 2);
	}
	std::cout << "\nContact added successfully !\n\n";
	return (pal);
}

int	Contact::display_book(int j, Contact pal)
{
	std::string	index;

	if (pal.nickname.empty())
		return (0);
	else if (j == 0)
		std::cout << "\n|   INDEX  | FST_NAME | LST_NAME | NICKNAME |\n";
	std::cout << "|-------------------------------------------|\n";
	std::cout << "|     " << (j + 1) << "    |";
	if (pal.first_name.size() < 10)
		std::cout << std::setw(10) << pal.first_name.substr(0, 9);
	else if (pal.first_name.size() == 10)
		std::cout << pal.first_name;
	else
		std::cout << pal.first_name.substr(0, 9) << '.';
	std::cout << '|';
	if (pal.last_name.size() < 10)
		std::cout << std::setw(10) << pal.last_name.substr(0, 9);
	else if (pal.last_name.size() == 10)
		std::cout << pal.last_name;
	else
		std::cout << pal.last_name.substr(0, 9) << '.';
	std::cout << '|';
	if (pal.nickname.size() < 10)
		std::cout << std::setw(10) << pal.nickname.substr(0, 9);
	else if (pal.nickname.size() == 10)
		std::cout << pal.nickname;
	else
		std::cout << pal.nickname.substr(0, 9) << '.';
	std::cout << "|\n";
	return (1);
}

void	Contact::display_pal(int j, Contact pal)
{
	std::cout << "* Contact no. " << j << " *\n\n";
	std::cout << "First name > " << pal.first_name << std::endl;
	std::cout << "Last name > " << pal.last_name << std::endl;
	std::cout << "Nickname > " << pal.nickname << std::endl;
	std::cout << "Phone Number > " << pal.phone_number << std::endl;
	std::cout << "Darkest Secret > " << pal.darkest_secret << std::endl;
}
