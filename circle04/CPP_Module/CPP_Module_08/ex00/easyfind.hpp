/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:28:25 by chukim            #+#    #+#             */
/*   Updated: 2022/11/25 10:40:10 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <list>
# include <iterator>
# include <vector>
# include <array>

template<typename T>
int easyfind(T const& t, int n)
{
	typename T::const_iterator end = t.end();
	typename T::const_iterator it = std::find(t.begin(), end, n);

	if (it == end)
	{
		throw(std::out_of_range("not found"));
	}
	else
		return (*it);
}

#endif
