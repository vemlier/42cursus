/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:52:04 by chukim            #+#    #+#             */
/*   Updated: 2022/10/26 14:13:29 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	this->type = "Aanimal";
	std::cout << "AAnimal was constructed\n";
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal was destroyed\n";
}

AAnimal::AAnimal(const AAnimal & ref)
{
	this->type = ref.getType();
	std::cout << "AAnimal was constructed from a copy\n";
}

AAnimal & AAnimal::operator=(AAnimal const & rhs)
{
	this->type = rhs.getType();
	return (*this);
}

void AAnimal::makeSound() const
{
	std::cout << "animal sound...\n";
}

std::string AAnimal::getType(void) const
{
	return (this->type);
}