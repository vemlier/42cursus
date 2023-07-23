/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:42:07 by chukim            #+#    #+#             */
/*   Updated: 2022/10/19 11:29:34 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	Fixed c = a;
	std::cout << Fixed::min(c, b) << std::endl;
	std::cout << b / Fixed(2) << std::endl;
	std::cout << b + Fixed(-3.14f) << std::endl;
	std::cout << b - Fixed(18) << std::endl;
	std::cout << (c != a) << std::endl;
	std::cout << (c == a) << std::endl;
	return 0; 
}
