/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:33:16 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/15 18:39:37 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

void	reverse(char c)
{
	if (std::isprint(c))
		std::cout << "char : '" << c << "'\n";
	else
		std::cerr << "char : Non displayable\n";
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << ".0f\n";
	std::cout << "double : " << static_cast<double>(c) << ".0\n";
}

void	toChar(double nb)
{
	char res = static_cast<char>(nb);

	if (!std::isfinite(nb) || nb < CHAR_MIN || nb > CHAR_MAX)
		std::cerr << "char : impossible\n";
	else if (!std::isprint(res))
		std::cerr << "char : Non displayable\n";
	else
		std::cout << "char : " << '\'' << res << "'\n" ;
}

void	toInt(double nb)
{
	if (!std::isfinite(nb) || nb < INT_MIN || nb > INT_MAX)
		std::cerr << "int : impossible\n";
	else
		std::cout << "int : " << static_cast<int>(nb) << std::endl;
}

void	toFloat(double nb)
{
	std::cout << "float : " << static_cast<float>(nb) << "f" << std::endl;
}
