/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:38:52 by chukim            #+#    #+#             */
/*   Updated: 2022/11/28 06:56:02 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm> 
# include <vector>
# include <iterator>
# include <cmath> //for abs

typedef std::vector<int>::iterator my_iter;

class Span
{
	public:
		Span(unsigned int capacity);
		~Span();
		Span(Span const & ref);
		Span const & operator=(Span const & ref);

		Span(int first, int last, int jump);

		unsigned int		getNInts(void) const;
		std::vector<int>	getVector(void) const;
		unsigned int		getNContents(void) const;

		void	addNumber(int n);
		int		longestSpan(void);
		int		shortestSpan(void);

		void	addNumber(my_iter start, my_iter end);
		

	private:
		unsigned int		_capacity;
		unsigned int		_size;
		std::vector<int>	_vector;
};

std::ostream & operator<<(std::ostream & o, Span const & rhs);

#endif
