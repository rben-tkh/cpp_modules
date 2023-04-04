/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:40:06 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/04/04 19:37:23 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	s_date::operator<(const s_date &other)const
{
	if (array[0] != other.array[0])
		return (array[0] < other.array[0]);
	if (array[1] != other.array[1])
		return (array[1] < other.array[1]);
	return (array[2] < other.array[2]);
}

bool	s_date::operator>(const s_date &other)const
{
	if (array[0] > other.array[0]) 
		return (true);
	else if (array[1] > other.array[1])
		return (true);
	else if (array[2] > other.array[2])
		return (true);
	return (false);
}

bool	s_date::operator==(const s_date &other)const
{
	if (array[0] == other.array[0] && array[1] == other.array[1] && array[2] == other.array[2])
		return (true);
	return (false);
}

BitcoinExchange::BitcoinExchange(void) : error(false)
{
	// std::cout << "Default constructor called !\n";
}

BitcoinExchange::BitcoinExchange(std::string csv, std::string txt) : error(false), str(txt)
{
	// std::cout << "Constructor called !\n";
	setData(toTab(csv));
	input = toTab(txt);
	if (error == false)
		parseInput();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &btc)
{
	// std::cout << "Copy constructor called !\n";
	*this = btc;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &btc)
{
	// std::cout << "Copy assignement operator called !\n";
	error = btc.error;
	input = toTab(btc.str);
	data = btc.data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	// std::cout << "Destructor called !\n";
	delete[] input;
}

bool	BitcoinExchange::getError(void)const
{
	return (error);
}

std::map<t_date, float>	BitcoinExchange::getData(void)const
{
	return (data);
}

std::string	*BitcoinExchange::getInput(void)const
{
	return (input);
}

void	BitcoinExchange::setData(std::string tab[])
{
	t_date	key;
	float	nb;

	for (int i = 0; !tab[i].empty(); i++)
	{
		key.array[0] = toLong(tab[i], '-', 1, "database");
		key.array[1] = toLong(tab[i], '-', 0, "database");
		key.array[2] = toLong(tab[i], ',', 0, "database");
		nb = toFloat(tab[i], "database");
		parseDate(key, "database");
		if (error == false)
			data[key] = nb;
		else
		{
			delete[] tab;
			return ;
		}
	}
	delete[] tab;
}

std::string	*BitcoinExchange::toTab(std::string str)
{
	int tmp = 0;
	int	len = 0;
	int	i = -1;

	while (str[++i])
	{
		if (str[i] == '\n' && (!str[i + 1] || str[i + 1] != '\n'))
		len++;
		if (!len)
			tmp++;
	}
	std::string	*stab = new std::string[len + 1];
	char		*str2 = std::strtok(&str[tmp], "\n");
	i = -1;
	while (str2)
	{
		stab[++i] = str2;
		str2 = std::strtok(NULL, "\n");
	}
	return (stab);
}

long	BitcoinExchange::toLong(std::string str, char c, int val, const char *msg)
{
	if (error == true)
		return (0);
	static int	i;
	int			count = 0;
	int			n = 1;
	long		nb = 0;

	if (val)
		i = 0;
	while (str[i] && std::isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	while (str[i] && std::isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		count++;
		i++;
	}
	while (str[i] && std::isspace(str[i]))
		i++;
	if (nb > INT_MAX || count > 10)
		return (std::cerr << msg <<": Too large a number => " << nb << std::endl, error = true, NULL);
	else if (!str[i] || (str[i] && str[i] != c))
		return (std::cerr << msg << ": Bad input => " << str << std::endl, error = true, NULL);
	return (i += 1, nb * n);
}

float	BitcoinExchange::toFloat(std::string str, const char *msg)
{
	if (error == true)
		return (0.0f);
	int	i = 0;
	int	count = 0;
	while ((str[i] && str[i] != ',' && str[i] != '|') || (str[i] && std::isspace(str[i])))
		i++;
	if (!str[i] || !str[i + 1])
		return (std::cerr << msg << ": Bad input => " << str << std::endl, error = true, NULL);
	i += 1;
	int	tmp = i;
	while (str[tmp] && (std::isdigit(str[tmp]) || str[tmp] == '.' || std::isspace(str[tmp])))
	{
		if (str[tmp] == '.')
			count++;
		tmp++;
	}
	float	nb = std::atof(&str[i]);
	long	nb2 = std::atol(&str[i]);
	if (nb < 0)
		return (std::cerr << msg << ": Not a positive number => " << nb2 << std::endl, error = true, NULL);
	else if (std::strcmp(msg, "database") && (nb2 > VAL_MAX || count > 10))
		return (std::cerr << msg << ": Too large a number => " << nb2 << std::endl, error = true, NULL);
	else if (nb2 > INT_MAX || count > 10)
		return (std::cerr << msg << ": Too large a number => " << nb2 << std::endl, error = true, NULL);
	else if (str[tmp] || count > 1)
		return (std::cerr << msg << ": Bad input => " << str << std::endl, error = true, NULL);
	return (nb);
}

void	BitcoinExchange::parseDate(t_date key, const char *msg)
{
	if (error == true)
		return ;
	if (key.array[0] < 1)
	{
		std::cerr << msg << ": Invalid year => " << key.array[0] << std::endl;
		error = true;
	}
	else if (key.array[1] < 1 || key.array[1] > 12)
	{
		std::cerr << msg << ": Invalid month => " << key.array[1] << std::endl;
		error = true;
	}
	else if (key.array[2] < 1 || key.array[2] > 31)
	{
		std::cerr << msg << ": Invalid day => " << key.array[2] << std::endl;
		error = true;
	}
}

void	BitcoinExchange::parseInput(void)
{
	t_date									key;
	float									nb;
	std::map<t_date, float>::const_iterator it;

	for (int i = 0; !input[i].empty(); i++)
	{
		key.array[0] = toLong(input[i], '-', 1, "error");
		key.array[1] = toLong(input[i], '-', 0, "error");
		key.array[2] = toLong(input[i], '|', 0, "error");
		nb = toFloat(input[i], "error");
		parseDate(key, "error");
		if (error == false)
		{
			it = data.lower_bound(key);
			std::cout << std::fixed << std::setprecision(2);
			if (it->first == key)
				std::cout << it->first << " => " << nb << " = " << nb * it->second << std::endl;
			else if (it-- == data.begin())
				std::cerr << "error: Date not found => " << key << std::endl;
			else
			{
				std::cout << it->first << " (date close to " << key << ") => ";
				std::cout << nb << " = " << nb * it->second << std::endl;
			}
		}
		error = false;
	}
}

std::ostream	&operator<<(std::ostream &out, const s_date &date)
{
	out << date.array[0] << '-' << date.array[1] << '-' << date.array[2];
	return (out);
}
