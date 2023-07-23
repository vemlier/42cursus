/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:25:05 by chukim            #+#    #+#             */
/*   Updated: 2022/11/21 13:25:13 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	public:
		// OCCF
		Array( )
		{
			n = 0;
			t = new T[1];
			t[0] = 0;
		}

		~Array()
		{
			delete [] this->t;
		}
		
		Array(Array const & ref) : n(ref.size())
		{
			T	*refT = ref.getT();
			t = new T[n];
			for (unsigned int i = 0; i < n; i++)
				t[i] = refT[i];
		}

		Array & operator=(Array const & ref)
		{
			T	*refT = ref.getT();
			this->n = ref.size();
			delete [] this->t;
			this->t = new T[n];
			for (unsigned int i = 0; i < n; i++)
				t[i] = refT[i];
			return (*this);
		}

		Array(unsigned int n) : n(n) {t = new T[n];}
		
		// [] operator
		T	& operator[](int i)
		{
			if (i < 0 || i >= static_cast<int>(this->n))
			{
				throw (std::exception());
			}
			else
				return (*(t + i));
		}
		
		// Getters:
		T	*getT(void) const
		{
			return (t);
		}

		unsigned int	size(void) const 
		{
			return (n);
		}
	
	private:
		T				*t;
		unsigned int	n;
};

template<typename T>
std::ostream & operator<<(std::ostream & o, Array< T > const & ref)
{
	for (unsigned int i = 0; i < ref.size(); i++)
		std::cout << "T[" << i << "] : " << (ref.getT())[i] << std::endl;
	return (o);
}

#endif
