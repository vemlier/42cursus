/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:41:54 by chukim            #+#    #+#             */
/*   Updated: 2022/10/19 11:32:10 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

int Fixed::getRawBits( void ) const
{
	return (this->value);
}

void	Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	setRawBits(rhs.getRawBits());
	return (*this);
}

Fixed::Fixed(int int_arg)
{
	setRawBits(int_arg << this->bits);
}

Fixed::Fixed(float float_arg)
{
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

std::ostream & operator<<( std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

// > < >= <= == !=
int Fixed::operator>(Fixed const & rhs) const
{
	if (this->getRawBits() > rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<(Fixed const & rhs) const
{
	if (this->getRawBits() < rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator>=(Fixed const & rhs) const
{
	if (this->getRawBits() >= rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<=(Fixed const & rhs) const
{
	if (this->getRawBits() <= rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator==(Fixed const & rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator!=(Fixed const & rhs) const
{
	if (this->getRawBits() != rhs.getRawBits())
		return (1);
	return (0);
}

Fixed Fixed::operator+(Fixed const & rhs) const
{
	Fixed ret(this->toFloat() + rhs.toFloat());
	
	return (ret);
}

Fixed Fixed::operator-( Fixed const & rhs) const
{
	Fixed ret(this->toFloat() - rhs.toFloat());
	
	return (ret);
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
	Fixed ret(this->toFloat() * rhs.toFloat());

	return (ret);
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
	Fixed ret(this->toFloat() / rhs.toFloat());
	
	return (ret);
}

Fixed & Fixed::operator++( void ) // Prefix (++F)
{
	this->value += 1;
	return (*this);
}

Fixed & Fixed::operator--( void ) // Prefix (--F)
{
	this->value -= 1;
	return (*this);
}

Fixed Fixed::operator++( int ) // Postfix (F++)
{
	Fixed	temp = *this;

	(this->value) +=1 ;
	return (temp);
}

Fixed Fixed::operator--( int ) // Postfix (F--)
{
	Fixed	temp = *this;

	(this->value) -=1 ;
	return (temp);
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}
	
const Fixed & Fixed::max(const Fixed & a, const Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}
	
Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}
