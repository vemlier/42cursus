/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:26:14 by chukim            #+#    #+#             */
/*   Updated: 2022/11/01 09:55:37 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data
{
	public:
		// OCCF
		Data();
		~Data();
		Data(std::string value);
		Data(Data const & ref);
		Data & operator=(Data const & ref);

		std::string getValue( void ) const;
	private:
		std::string _value;
};

#endif
