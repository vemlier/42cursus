/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:48:35 by chukim            #+#    #+#             */
/*   Updated: 2022/10/25 09:57:36 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

	public:
		void set_name(std::string name);
		void set_hitpoints(unsigned int hitpoints);
		void set_energy_points(unsigned int energy_points);
		void set_attack_damage(unsigned int attack_damage);

		std::string get_name(void) const;
		unsigned int get_hitpoints(void) const;
		unsigned int get_energy_points(void) const;
		unsigned int get_attack_damage(void) const;
		
		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		ClapTrap(std::string name);
		ClapTrap(const ClapTrap & src);
		~ClapTrap();

		ClapTrap & operator=(const ClapTrap & rhs);
};
#endif