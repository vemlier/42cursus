/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:39:01 by chukim            #+#    #+#             */
/*   Updated: 2022/11/21 13:25:21 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *array, size_t array_length, void (*f)(T const &ref))
{
	for(size_t i = 0; i < array_length; i++)
		f(array[i]);
}

// Test function
template<typename T>
void	display(T const &t)
{
	std::cout << t << " ";
}

template<typename T>
void tests(T t, int len, std::string type)
{
	std::cout << std::endl << type << std::endl;
	std::cout << "----------------------------" << std::endl;
	iter(t, len, display);
	std::cout << std::endl << std::endl;
}

#endif
