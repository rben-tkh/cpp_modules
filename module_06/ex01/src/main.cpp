/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:55:02 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/15 18:49:55 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

static bool	check_input(char *str)
{
	std::string	check = str;
	int	i = 0;
	int	count = 0;

	if (check == "nan" || check == "-inf" || check == "inf" || check == "+inf")
		return (true);
	else if (check == "nanf" || check == "-inff" || check == "inff" || check == "+inff")
		return (true);
	else if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] && str[i] >= '0' && str[i] <= '9') || (str[i] && str[i] == '.'))
	{
		if (str[i] == '.')
			count++;
		i++;
	}
	if (count > 1 || (i == 0 && str[i] == 'f'))
		return (false);
	else if ((str[i] && str[i] != 'f') || (str[i] && str[i] == 'f' && str[i + 1]))
		return (false);
	return (true);
}

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

static void	display(int	error, char c, int i)
{
	if (error > 3)
		std::cerr << "char : impossible\n";
	else if (error == 2 || error == 3)
		std::cerr << "char : Non displayable\n";
	else
		std::cout << "char : " << '\'' << c << '\'' << std::endl;
	if (error % 2)
		std::cerr << "int : impossible\n";
	else
		std::cout << "int : " << i << std::endl;
}

int	main(int ac, char **av)
{
	if (ac != 2 || !av[1] || check_input(av[1]) == false)
		return (std::cerr << "Invalid argument !\n", -1);

	double	res = std::atof(av[1]);
	Data		data = Data(res);
	uintptr_t	raw = serialize(&data);
	Data		*ptr = deserialize(raw);

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "data : " << &data << " -> " << serialize(&data) << "\n";
	display(data.getError(), data.getC(), data.getI());
	std::cout << "float : " << data.getF() << 'f' << std::endl;
	std::cout << "double : " << data.getD() << "\n\n";
	std::cout << "ptr : " << ptr << " -> " << serialize(ptr) << "\n";
	display(data.getError(), ptr->getC(), ptr->getI());
	std::cout << "float : " << ptr->getF() << 'f' << std::endl;
	std::cout << "double : " << ptr->getD() << "\n\n";
	std::cout << "ptr == &data : " << std::boolalpha;
	std::cout << (ptr == &data) << std::endl;

	return (0);
}
