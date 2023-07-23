/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:52:29 by chukim            #+#    #+#             */
/*   Updated: 2022/10/29 12:59:34 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain;
	std::cout << "A dog was constructed with its brain\n";
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "A dog was destroyed and his brain deleted\n";
}

Dog::Dog(const Dog & ref)
{
	std::cout << "Creating a copy dog brain\n";
	this->brain = new Brain(*(ref.getBrain()));
	this->type = ref.getType();
	std::cout << "A dog was constructed as a dog copy. It has a brain\n";
}

Dog & Dog::operator=(const Dog & rhs)
{
	if (this->brain)
		delete (this->brain);
	this->brain = new Brain;
	this->type = rhs.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Wal Wal\n";
}

Brain *Dog::getBrain(void) const
{
	return (this->brain);
}
