/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:50:14 by chukim            #+#    #+#             */
/*   Updated: 2022/10/26 13:50:14 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "Constructor" << std::endl;
	std::cout << "--------------------" << std::endl;
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "getType()" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "makeSound()" << std::endl;
	std::cout << "--------------------" << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "Constructor" << std::endl;
	std::cout << "--------------------" << std::endl;
	const WrongAnimal* wrong_animal = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "makeSound()" << std::endl;
	std::cout << "--------------------" << std::endl;
	wrong_cat->makeSound();
	wrong_animal->makeSound();
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;
	delete wrong_cat;
	delete wrong_animal;

	return 0;
}
