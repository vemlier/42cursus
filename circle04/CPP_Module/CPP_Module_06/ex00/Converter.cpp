/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 07:57:21 by chukim            #+#    #+#             */
/*   Updated: 2022/11/01 09:23:59 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <limits.h>

static	void ft_msg(std::string msg)
{
	std::cout << msg << std::endl;
}

// OCCF
Converter::Converter() : _str("Default")
{
	ft_msg("A Converter has been constructed by default");
}

Converter::Converter(std::string str) : _str(str)
{
	ft_msg("A Converter has been constructed");
}

Converter::~Converter()
{
	ft_msg("A Converter has been destroyed");
}

Converter::Converter(const Converter & ref)
{
	_str = ref.getStr();
	ft_msg("A Converter has been constructed from copy");
}

Converter &	Converter::operator=(const Converter & ref)
{
	_str = ref.getStr();
	ft_msg("Assignement operator called");
	return (*this);
}

// Getter
std::string Converter::getStr(void) const
{
	return (this->_str);
}

// Char
static int	ft_is_displayable_char(char c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

Converter::operator char()
{
	char c = 0;
	if (_str.length() == 1)
	{
		int d = 0;
		// d = stoi(_str);
		// c = static_cast<char>(d);
		try
		{
			d = stoi(_str);
			c = static_cast<char>(d);
		}
		catch (const std::invalid_argument& ia){
			c = _str[0];
		}
		if (ft_is_displayable_char(c))
			std::cout << "[" << _str << "]" << " char: " << c << std::endl;
		else
			std::cout << "[" << _str << "]" << " char: " << "Non displayable!" << std::endl;
		return (c);
	}
	else
	{
		int	d = 0;
		try
		{
			d = stoi(_str);
		}
		catch (const std::invalid_argument& ia){
			std::cout << "[" << _str << "] char: ";
			ft_msg("impossible");
			return (0);
		}
		catch (const std::out_of_range& oor) {
			std::cout << "[" << _str << "] char: ";
			ft_msg("impossible");
			return (0);
		}
		if (d < CHAR_MIN || d > CHAR_MAX)
		{
			std::cout << "[" << _str << "] char: ";
			ft_msg("impossible");
			return (0);
		}
		c = static_cast<char>(d);
		if (ft_is_displayable_char(c))
			std::cout << "[" << _str << "] char: " << c << std::endl;
		else
			std::cout << "[" << _str << "] char: " << "Non displayable" << std::endl;
		return (c);
	}
}

// Int
Converter::operator int()
{
	int	d = 0;

	try
	{
		d = stoi(_str);
	}
	catch (const std::invalid_argument& ia){
		std::cout << "[" << _str << "] as an int: ";
		ft_msg("impossible");
		return (0);
	}
	catch (const std::out_of_range& oor) {
		std::cout << "[" << _str << "] as an int : ";
		ft_msg("impossible");
		return (0);
	}
	std::cout << "[" << _str << "] int: " << d << std::endl;
	return (d);
}

// Float
Converter::operator float()
{
	float	f = 0;
	std::cout << "[" << _str << "] float: " << f << "f" << std::endl;
	try
	{
		f = stof(_str);
		std::cout << "[" << _str << "] float: " << f << "f" << std::endl;
	}
	catch (const std::invalid_argument& ia){
		std::cout << "[" << _str << "] float: ";
		ft_msg("impossible");
		return (f);
	}
	catch (const std::out_of_range& oor) {
		std::cout << "[" << _str << "] float: ";
		ft_msg("impossible");
		return (f);
	}
	return (f);
}

// Double
Converter::operator double()
{
	double	d = 0;
	try
	{
		d = stod(_str);
		std::cout << "[" << _str << "] double: " << d << std::endl;
	}
	catch (const std::invalid_argument& ia){
		std::cout << "[" << _str << "] double: ";
		ft_msg("Impossible");
		return (d);
	}
	catch (const std::out_of_range& oor) {
		std::cout << "[" << _str << "] as a double: ";
		ft_msg("Impossible");
		return (d);
	}
	return (d);
}
