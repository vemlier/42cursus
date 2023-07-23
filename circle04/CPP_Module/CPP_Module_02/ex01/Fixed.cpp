/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:21:47 by chukim            #+#    #+#             */
/*   Updated: 2022/10/19 11:25:15 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & origin)
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(origin.getRawBits());
	return (*this);
}

Fixed::Fixed(int int_arg)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(int_arg << this->bits);
}

Fixed::Fixed(float float_arg)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(float_arg * (1 << this->bits)));
}

float Fixed::toFloat(void) const
{
	float	f;

	f = (float)this->getRawBits() / (1 << this->bits);
	return (f);
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->bits);
}

std::ostream & operator<<( std::ostream & o, Fixed const & origin)
{
	o << origin.toFloat();
	return (o);
}


