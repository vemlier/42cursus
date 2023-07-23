/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 07:57:28 by chukim            #+#    #+#             */
/*   Updated: 2022/11/01 08:17:34 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>

class Converter
{
	public:
		// OCCF
		Converter();
		Converter(std::string str);
		~Converter();
		Converter(const Converter & ref);
		Converter &	operator=(const Converter & ref);

		// Getter
		std::string getStr(void) const;

		// Conversions
		operator char();
		operator int();
		operator float();
		operator double();

	private:
		std::string	_str;

};
#endif
