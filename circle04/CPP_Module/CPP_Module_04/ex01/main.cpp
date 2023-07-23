/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:51:35 by chukim            #+#    #+#             */
/*   Updated: 2022/10/26 13:51:35 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main( void )
{
	std::cout << "Constructor" << std::endl;
	std::cout << "--------------------" << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "Destructor" << std::endl;
	std::cout << "--------------------" << std::endl;
	delete dog;
	delete cat;
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "Array" << std::endl;
	std::cout << "--------------------" << std::endl;
	const Animal	*(animal_array[4]);

	for (int i = 0; i < 2; i++)
		animal_array[i] = new Dog();
	std::cout << std::endl;

	for (int i = 2; i < 4; i++)
		animal_array[i] = new Cat();
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "Destructor" << std::endl;
	std::cout << "--------------------" << std::endl;
	for (int i = 0; i < 4; i++)
		delete animal_array[i];
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	Dog dog1;
	Dog & dog1_ref = dog1;
	std::cout << std::endl << "creating copies" << std::endl;
	Dog dog1_copy(dog1_ref);
	Dog & dog1_copy_ref = dog1_copy;
	std::cout << std::endl << "comparing" << std::endl;
	dog1.compareTo(dog1_copy_ref);
	std::cout << std::endl;

	system("leaks ex01");

	return 0;
}
