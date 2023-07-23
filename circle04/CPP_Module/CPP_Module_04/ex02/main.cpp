/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:52:37 by chukim            #+#    #+#             */
/*   Updated: 2022/10/26 13:52:37 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main( void )
{
	std::cout << "Constructor" << std::endl;
	std::cout << "--------------------" << std::endl;
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();
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
	const AAnimal	*(animal_array[4]);

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

	//const AAnimal a = new AAnimal();
	system("leaks ex02");

	return 0;
}
