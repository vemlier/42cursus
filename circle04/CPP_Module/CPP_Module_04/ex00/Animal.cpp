/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:49:43 by chukim            #+#    #+#             */
/*   Updated: 2022/10/26 13:49:44 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal was constructed\n";
	this->type = "animal";
}

Animal::~Animal()
{
	std::cout << "Animal was destroyed\n";
}

Animal::Animal(const Animal & ref)
{
	this->type = ref.type;
	std::cout << "Animal was constructed from a copy\n";
}

Animal & Animal::operator=(Animal const & rhs)
{
	this->type = rhs.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "animal sound...\n";
}

std::string Animal::getType(void) const
{
	return (this->type);
}