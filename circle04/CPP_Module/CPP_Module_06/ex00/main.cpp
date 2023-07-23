/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 07:57:33 by chukim            #+#    #+#             */
/*   Updated: 2022/11/01 09:24:29 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Converter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Argument error\n";
		return (0);
	}
	std::cout << std::fixed << std::setprecision(1);
	std::string	argument = argv[1];
	
	Converter	converter(argument);

	char	c;
	int		n;
	float	f;
	double	d;

	c = static_cast<char>(converter);
	n = static_cast<int>(converter);
	f = static_cast<float>(converter);
	d = static_cast<double>(converter);

	return (0);
}
