/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:26:18 by chukim            #+#    #+#             */
/*   Updated: 2022/11/01 09:55:17 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

static void ft_msg(std::string msg)
{
	std::cout << msg << std::endl;
}

// OCCF
Data::Data()
{
	this->_value = "Default";
	ft_msg("A Data has been contructed by default");
}

Data::~Data()
{
	ft_msg("A Data has been destroyed");
}

Data::Data(std::string value) : _value(value)
{
	ft_msg("A Data has been contructed");
}

Data::Data(Data const & ref) : _value(ref.getValue())
{
	ft_msg("A Data has been contructed by copy");
}

Data & Data::operator=(Data const & ref)
{
	this->_value = ref.getValue();
	ft_msg("Assignement operator called");
	return (*this);
}

std::string Data::getValue( void ) const
{
	return (_value);
}
