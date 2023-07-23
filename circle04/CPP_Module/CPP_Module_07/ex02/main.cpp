/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:25:10 by chukim            #+#    #+#             */
/*   Updated: 2022/11/17 12:19:21 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	// Empty
	std::cout << std::endl << "Empty array" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Array<int>	arr;
	try
	{
		std::cout << "Acessing element 0: " << arr[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	// INT
	std::cout << std::endl << "Int array" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Array<int> iarr(4);
	std::cout << "Before assigning: \n" << iarr << std::endl;
	iarr[0] = 0;
	iarr[1] = 42;
	iarr[2] = -42;
	iarr[3] = 256;
	std::cout << "After assigning: \n" << iarr << std::endl;

	// CHAR
	std::cout << std::endl << "Char array" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Array<char> carr(4);
	std::cout << "Before assigning: \n" << carr << std::endl;
	carr[0] = 'a';
	carr[1] = 'b';
	carr[2] = 'c';
	carr[3] = 'd';
	std::cout << "After assigning: \n" << carr << std::endl;

	// FLOAT
	std::cout << std::endl << "Float array" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Array<float> farr(4);
	std::cout << "Before assigning: \n" << farr << std::endl;
	farr[0] = 3.14f;
	farr[1] = -4.2f;
	farr[2] = 0.0f;
	farr[3] = 22.22f;
	std::cout << "After assigning: \n" << farr << std::endl;

	// STRING
	std::cout << std::endl << "String array" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Array<std::string> sarr(4);
	std::cout << "Before assigning: \n" << sarr << std::endl;
	sarr[0] = "first string";
	sarr[1] = "second string";
	sarr[2] = "third string";
	sarr[3] = "fourth string";
	std::cout << "After assigning: \n" << sarr << std::endl;
	
	system("leaks ex02");
	return (0);
}
