/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:23:08 by chukim            #+#    #+#             */
/*   Updated: 2022/10/13 12:07:56 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string _type) : type(_type)
{
}

Weapon::~Weapon()
{
}

std::string	const &Weapon::getType() const
{
	return (this->type);
}

void	Weapon::setType(std::string new_type)
{
	this->type = new_type;
}