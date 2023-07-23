/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:47:23 by chukim            #+#    #+#             */
/*   Updated: 2022/10/25 10:31:28 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::attack(std::string const & target)
{
	std::string		class_name = "ClapTrap";
	std::string		name = this->_name;
	unsigned int	dmg = this->_attack_damage;

	if (this->_hitpoints == 0)
	{
		std::cout << class_name << " " << name << " is dead\n";
		return ;
	}
	if (this->_energy_points >= 1)
	{
		std::cout << class_name << " " << name << " attacks " << target << " causing " << dmg << " points of damage!\n";
		std::cout << "This attack cost " << class_name << " " << name << " " << 1 << " energy points\n";
		this->_energy_points -= 1;
	}
	else
	{
		std::cout << class_name << " " << name << " can't attack \n";
	}
	std::cout << class_name << " " << name << " has " << this->_energy_points << " energy points\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::string		class_name = "ClapTrap";
	std::string		name = this->_name;

	if (this->_hitpoints == 0)
	{
		std::cout << class_name << " " << name << " is dead\n";
		return ;
	}
	std::cout << class_name << " "  << name << " got " << amount << " points of damage!\n";
	if (amount > this->_hitpoints)
		this->_hitpoints = 0;
	else
		this->_hitpoints -= amount;
	std::cout << class_name << " "  << name << " has " << this->_hitpoints << " hit point\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::string		class_name = "ClapTrap";
	std::string		name = this->_name;
	unsigned int	max_hp = 10;

	if (this->_hitpoints == 0)
	{
		std::cout << class_name << " " << name << " is already dead\n";
		return ;
	}
	else if (this->_energy_points <= 0)
	{
		std::cout << class_name << name << " has no energy\n";
		return ;
	}
	std::cout << class_name << " "  << name << " was repaired for " << amount << " points of damage!\n";
	this->_energy_points -= 1;
	if (this->_hitpoints + amount >= max_hp)
	{
		this->_hitpoints = max_hp;
		std::cout << class_name << " "  << name << " is now fully healed!\n";
	}
	else
		this->_hitpoints += amount;
	std::cout << class_name << " "  << name << " has " << this->_hitpoints << " hit point\n";
}

void ClapTrap::set_name(std::string name)
{
	this->_name = name;
}

void ClapTrap::set_hitpoints(unsigned int hitpoints)
{
	this->_hitpoints = hitpoints;
}

void ClapTrap::set_energy_points(unsigned int energy_points)
{
	this->_energy_points = energy_points;
}

void ClapTrap::set_attack_damage(unsigned int attack_damage)
{
	this->_attack_damage = attack_damage;
}

std::string ClapTrap::get_name(void) const
{
	return (this->_name);
}

unsigned int ClapTrap::get_hitpoints(void) const
{
	return (this->_hitpoints);
}

unsigned int ClapTrap::get_energy_points(void) const
{
	return (this->_energy_points);
}

unsigned int ClapTrap::get_attack_damage(void) const
{
	return (this->_attack_damage);
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::string class_name = "ClapTrap";

	this->_attack_damage = 0;
	this->_energy_points = 10;
	this->_hitpoints = 10;
	std::cout << class_name << " "  << this->_name << " has been created\n";
}

ClapTrap::ClapTrap(const ClapTrap & src)
{
	std::string 	name;
	std::string		class_name = "ClapTrap";

	name = src.get_name() + "copy";
	this->set_name(name);
	this->_attack_damage = 0;
	this->_energy_points = 10;
	this->_hitpoints = 10;
	std::cout << class_name << " copy "  << this->_name << " has been created\n";
}

ClapTrap::~ClapTrap()
{
	std::string		class_name = "ClapTrap";

	std::cout << class_name << " "  << this->_name << " is now destroyed...\n";
}

ClapTrap & ClapTrap::operator=(const ClapTrap & rhs)
{
	this->set_name(rhs.get_name());
	this->_attack_damage = rhs.get_attack_damage();
	this->_energy_points = rhs.get_energy_points();
	this->_hitpoints = rhs.get_hitpoints();
	return (*this);
}