/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:02:06 by chukim            #+#    #+#             */
/*   Updated: 2023/07/20 21:01:52 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>

int main(int ac, char* av[])
{
	if (ac <= 1)
	{
		std::cout << "Arguments error" << std::endl;
		return (1);
	}
	PmergeMe pmergeMe(ac, av);
	(void)pmergeMe;
	return (0);
}
