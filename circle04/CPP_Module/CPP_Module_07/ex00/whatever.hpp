/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:39:17 by chukim            #+#    #+#             */
/*   Updated: 2022/11/21 13:25:38 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

// -------------------------- REQUIRED FUNCTIONS ------------------------------

template<typename T>
void swap(T & x, T & y)
{
	T	temp;
	temp = x;
	x = y;
	y = temp;
}

template<typename T>
T const &	min(T const & x, T const & y)
{
	return (x < y ? x : y);
}

template<typename T>
T const &	max(T const & x, T const & y)
{
	return (x > y ? x : y);
}

#endif
