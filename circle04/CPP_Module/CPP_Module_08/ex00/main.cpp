/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:38:35 by chukim            #+#    #+#             */
/*   Updated: 2022/11/25 10:40:38 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	ft_display(int i)
{
	std::cout << i << std::endl;
}

void	ft_list_tests(void)
{
	std::list<int> lst;
	for (int i = 1; i <= 5; i++)
		lst.push_back(i);
	
	std::cout << std::endl;
	std::cout << "List" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::for_each(lst.begin(), lst.end(), ft_display);
	std::cout << std::endl;

	std::cout << "list : 2" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << easyfind(lst, 2) << std::endl << std::endl; 
	std::cout << "lst : -1" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	try
	{
		std::cout << easyfind(lst, -1) << std::endl << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void	ft_vector_tests(void)
{
	std::vector<int> vector;

	for (int i = 1; i <= 5; i++)
		vector.push_back(i);

	std::cout << std::endl;
	std::cout << "Vector" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::for_each(vector.begin(), vector.end(), ft_display);
	std::cout << std::endl;

	std::cout << "vector : 2" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << easyfind(vector, 2) << std::endl << std::endl;
	std::cout << "vector : -1" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	try
	{
		std::cout << easyfind(vector, -1) << std::endl << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void	ft_array_tests(void)
{
	std::array<int, 5> array;

	for (int i = 1; i <= 5; i++)
		array[i - 1] = i;

	std::cout << std::endl;
	std::cout << "Array" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::for_each(array.begin(), array.end(), ft_display);
	std::cout << std::endl;

	std::cout << "array : 2" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << easyfind(array, 2) << std::endl << std::endl;
	std::cout << "array : -1" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	try
	{
		std::cout << easyfind(array, -1) << std::endl << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

int main(void)
{
	ft_list_tests();
	ft_vector_tests();
	ft_array_tests();
	return (0);
}
