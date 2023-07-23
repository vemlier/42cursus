/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:42:02 by chukim            #+#    #+#             */
/*   Updated: 2022/10/19 11:30:48 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const & src);

		Fixed & operator=( Fixed const & rhs);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		Fixed(int const int_arg);
		Fixed(float const float_arg);

		float toFloat(void) const;
		int toInt(void) const;

		int operator>(Fixed const & rhs) const;
		int operator<(Fixed const & rhs) const;
		int operator>=(Fixed const & rhs) const;
		int operator<=(Fixed const & rhs) const;
		int operator==(Fixed const & rhs) const;
		int operator!=(Fixed const & rhs) const;
		
		Fixed operator+(Fixed const & rhs) const;
		Fixed operator-(Fixed const & rhs) const;
		Fixed operator*(Fixed const & rhs) const;
		Fixed operator/(Fixed const & rhs) const;

		Fixed & operator++(void );
		Fixed & operator--(void );
		Fixed operator++(int n );
		Fixed operator--(int n );

		static Fixed & min(Fixed & a, Fixed & b );
		static Fixed & max(Fixed & a, Fixed & b );
		static const Fixed & min(const Fixed & a, const Fixed & b );
		static const Fixed & max(const Fixed & a, const Fixed & b );

	private:
		int	value;
		static const int bits = 8;
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

#endif
