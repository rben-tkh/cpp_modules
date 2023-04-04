/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 08:11:27 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/12/31 08:11:27 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

static std::string	getnewfd(std::string s1, std::string s2, std::streambuf *c)
{
	size_t	size = c->in_avail();
	char str[size + 1];
	for (int i(0); c->sgetc() != EOF; i++)
		str[i] = c->sbumpc();
	str[size] = '\0';
	std::string new_strfd, strfd = str;
	size_t ptr;
	while (1)
	{
		ptr = strfd.find(s1);
		if (ptr == std::string::npos)
		{
			new_strfd.append(strfd);
			return (new_strfd);
		}
		new_strfd.append(strfd, 0, ptr);
		new_strfd.append(s2);
		strfd = strfd.substr(ptr + s1.size());
	}
}

int	main(int ac, char **av)
{
	if (ac == 4 && av[2][0])
	{
		std::fstream file(av[1]);
		if (!file.is_open())
			return (std::perror(av[1]), -1);
		std::string s1 = av[2], s2 = av[3];
		std::strcat(av[1], ".replace");
		std::fstream new_file;
		new_file.open(av[1], std::ios_base::out);
		if (!new_file.is_open())
			return (std::remove(av[1]), std::perror(av[1]), -1);
		new_file << getnewfd(s1, s2, file.rdbuf());
		new_file.close();
		file.close();
	}
	else
		return (std::cout << "Invalid argument !\n", -1);
	return (0);
}
