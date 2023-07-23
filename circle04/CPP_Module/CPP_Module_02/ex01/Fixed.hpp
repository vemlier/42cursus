/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:21:52 by chukim            #+#    #+#             */
/*   Updated: 2022/10/19 11:24:59 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

// CANONIC FORM
// Class containing at least:
// 1) Constructor default
// 2) Copy constructor
// 3) '=' Operator overload
// 4) Destructor (virtual!)

class	Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const & src);
		Fixed(int const int_arg);
		Fixed(float const float_arg);

		Fixed & operator=(Fixed const & origin);
		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

	private:
		int	value;
		static const int bits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & origin);

#endif
