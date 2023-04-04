/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:57:42 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/04/01 19:55:03 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstring>
# include <cstdlib>
# include <climits>
# include <chrono>
# include <algorithm>
# include <iterator>
# include <vector>
# include <list>

/*------------------------------------PGM------------------------------------*/

class PmergeMe
{
	public:
							PmergeMe(void);
							PmergeMe(char **arg);
							PmergeMe(const PmergeMe &pgm);
		PmergeMe			&operator=(const PmergeMe &pgm);
							~PmergeMe(void);

		bool				getError(void)const;
		std::vector<int>	getVec(void)const;
		std::list<int>		getLst(void)const;

		void				addNumber(char *str, int i);
		void				init(char **arg);
		bool				parse(void);

		template <typename T>
		void				print(T it, T end);
		template <typename T, typename U>
		void 				insert(U begin, U end);
		template <typename T, typename U>
		void				sort(T &container, U begin, U end);
		template <typename T>
		void				exec(T &container, const char *name, bool display);

	private:
		bool				error;
		std::vector<int>	vec;
		std::list<int>		lst;
};

/*------------------------------------T^T------------------------------------*/

#endif
