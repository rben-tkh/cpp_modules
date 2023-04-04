/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:19:28 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/12/29 21:51:04 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"
#include "../inc/Phonebook.hpp"

static int	get_index(int j)
{
	std::string	index;

	std::cout << std::endl;
	while (index.empty())
	{
		std::cout << "Index (1";
		if (j > 1)
			std::cout << "-" << j;
		std::cout << " or EXIT) : ";
		if (!std::getline(std::cin, index) || index == "EXIT")
			return (0);
		if (!index[0] || index[1] || index[0] <= '0' || index[0] > (j + '0'))
		{
			index.clear();
			std::cout << "\nInvalid Index !\n\n";
		}
	}
	return (std::cout << std::endl, index[0] - '0');
}

static void	search_pal(Phonebook book)
{
	int			j(-1);
	int			index(-1);

	while (++j < 8 && book.pal[j].display_book(j, book.pal[j]));
	if (j > 0)
	{
		index = (get_index(j) - 1);
		if (index > -1)
			book.pal[index].display_pal((index + 1), book.pal[index]);
	}
	else
		std::cout << "\nYou currently have no contacts.\n";
	std::cout << std::endl;
	j = -1;
}

std::string	check_input(std::string input, std::string info, int val)
{
	int	i(0);

	if (input[i] && input[i] <= ' ')
		return (std::cout << "\nInvalid " << info, input.clear(), input);
	while (input[i])
	{
		if (input[i] < ' ')
			return (std::cout << "\nInvalid " << info, input.clear(), input);
		else if (i > 0 && input[i - 1] == ' ' && input[i] == ' ')
			return (std::cout << "\nInvalid " << info, input.clear(), input);
		else if (val == 0 && !(input[i] >= 'a' && input[i] <= 'z')
		 && !(input[i] >= 'A' && input[i] <= 'Z') && input[i] != ' ')
			return (std::cout << "\nInvalid " << info, input.clear(), input);
		else if (val == 1 && !(input[i] >= '0' && input[i] <= '9'))
			return (std::cout << "\nInvalid " << info, input.clear(), input);
		i++;
	}
	if (i > 0 && input[i - 1] == ' ')
		return (std::cout << "\nInvalid " << info, input.clear(), input);
	return (input);
}

int	main(void)
{
	std::string	input;
	Phonebook	book;
	int			i(-1);

	std::cout << "\t* MY AWESOME PHONEBOOK *\n\n";
	while (1)
	{
		if (i > 6)
			i = -1;
		std::cout << "Enter command (ADD, SEARCH, EXIT) : ";
		if (!std::getline(std::cin, input))
			return (std::cout << std::endl, -1);
		else if (input == "ADD" && ++i < 8)
			book.pal[i] = book.pal[i].add_pal();
		else if (input == "SEARCH")
			search_pal(book);
		else if (input == "EXIT")
			return (0);
		else
			std::cout << "\nInvalid Command !\n\n";
		if (std::cin.fail())
			return (std::cout << std::endl, -1);
	}
	return (0);
}
