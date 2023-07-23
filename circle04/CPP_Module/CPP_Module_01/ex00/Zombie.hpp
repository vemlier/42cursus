/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:17:53 by chukim            #+#    #+#             */
/*   Updated: 2022/09/17 14:17:53 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private: 
		const std::string	name;

	public:
		Zombie(std::string _name);
		Zombie();
		~Zombie();
		void announce(void) const;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif