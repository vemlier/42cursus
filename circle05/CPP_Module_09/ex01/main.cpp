/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:01:43 by chukim            #+#    #+#             */
/*   Updated: 2023/07/20 08:13:24 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Arguments error" << std::endl;
		return (1);
	}

	std::string input = argv[1];
	RPN calculator;
	calculator.calculate(input);

	return (0);
}
