/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:40:06 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/03/30 14:46:21 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstring>
# include <cstdlib>
# include <ctime>
# include <climits>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <utility>
# include <map>

# define VAL_MAX 1000

/*-----------------------------------S_DATA-----------------------------------*/

typedef struct s_date
{
	long			array[3];
	bool			operator<(const s_date &other)const;
	bool			operator>(const s_date &other)const;
	bool			operator==(const s_date &other)const;
}	t_date;

/*-----------------------------------C_BTC-----------------------------------*/

class BitcoinExchange
{
	public:
								BitcoinExchange(void);
								BitcoinExchange(std::string csv, std::string txt);
								BitcoinExchange(const BitcoinExchange &btc);
		BitcoinExchange			&operator=(const BitcoinExchange &btc);
								~BitcoinExchange(void);


		bool					getError(void)const;
		std::map<t_date, float>	getData(void)const;
		std::string				*getInput(void)const;
		void					setData(std::string tab[]);

		std::string				*toTab(std::string str);
		long					toLong(std::string str, char c, int val, const char *msg);
		float					toFloat(std::string str, const char *msg);
		void					parseDate(t_date key, const char *msg);
		void					parseInput(void);

	private:
		bool					error;
		std::string				str;
		std::map<t_date, float>	data;
		std::string				*input;
};

/*----------------------------------OPERATOR---------------------------------*/

std::ostream	&operator<<(std::ostream &out, const s_date &date);

/*------------------------------------T^T------------------------------------*/

#endif
