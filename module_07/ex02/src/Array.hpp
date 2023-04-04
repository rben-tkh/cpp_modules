/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:11:31 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/02/20 00:11:32 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>
# include <cctype>

/*----------------------------------CT_ARRAY---------------------------------*/

template <class T>
class Array
{
	public:
		Array(void) : array(new T[0]), len(0){}
		Array(unsigned int n) : array(new T[n]), len(n){}
		Array(const Array<T> &ref)
		{
			*this = ref; 
		}
		Array<T>	&operator=(const Array<T> &ref)
		{
			len = ref.size();
			array = new T[len];
			for (int i = 0; i < len; i++)
				array[i] = ref.array[i];
			return (*this);
		}
		~Array(void)
		{
			delete []array;
		}

		T		&operator[](const int idx)
		{
			if (!array || idx < 0 || idx >= len)
				throw NotInArray();
			return (array[idx]);
		}

		T		getArray(int idx)const
		{
			if (!array)
				return (0);
			else if (idx < 0 || idx >= len)
				throw NotInArray();
			return (array[idx]);
		}
		int		size(void)const
		{
			return (len);
		}

		class NotInArray : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return ("Not in array !");
				} 
		};

	private:
		T		*array;
		int		len;
};

/*------------------------------------T^T------------------------------------*/

#endif
