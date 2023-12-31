/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:20:20 by chukim            #+#    #+#             */
/*   Updated: 2022/10/12 09:31:12 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <sstream>

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::stringstream ss;
		ss << (i + 1);
		std::string str;
    	ss >> str;
		horde[i].set_name(name + " " + str);
		horde[i].announce();
	}
	return (horde);
}