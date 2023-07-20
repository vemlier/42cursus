/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:02:06 by chukim            #+#    #+#             */
/*   Updated: 2023/07/20 08:45:37 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>

int main(int ac, char* av[])
{
	if (ac <= 1)
	{
		std::cerr << "Arguments error" << std::endl;
		return (1);
	}
	PmergeMe pmergeMe(ac, av);
	(void)pmergeMe;
	return (0);
}
