/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:00:21 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/03/12 18:00:21 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <vector>
# include <algorithm>

/*-----------------------------------C_SPAN----------------------------------*/

class Span
{
	public:
								Span(void);
								Span(unsigned int new_max);
								Span(const Span &span);
		Span					&operator=(const Span &span);
								~Span(void);

		const std::vector<int>		&getVec(void)const;
		unsigned int			getMax(void)const;

		void					addNumber(int nb);
		void					addMutipleNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
		int						shortestSpan(void);
		int						longestSpan(void);

		class SpanFull : public std::exception
		{
			virtual const char *what(void)const throw();	
		};
		class DistanceNotFind : public std::exception
		{
			virtual const char *what(void)const throw();	
		};

	private:
		unsigned int			max;
		std::vector<int>		vec;
};

/*------------------------------------T^T------------------------------------*/

#endif
