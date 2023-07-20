/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:32:48 by chukim            #+#    #+#             */
/*   Updated: 2023/07/20 08:10:10 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>

int main(int argc , char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Arguments error" << std::endl;
		return (1);
	}
	Btc btc;
	btc.readInput(argv[1]);
	return (0);
}
