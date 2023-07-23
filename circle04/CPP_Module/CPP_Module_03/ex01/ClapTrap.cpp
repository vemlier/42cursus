/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:48:42 by chukim            #+#    #+#             */
/*   Updated: 2022/10/25 10:31:45 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

const unsigned int	ClapTrap::_class_hp = 10;
const unsigned int	ClapTrap::_class_energy_points = 10;
const unsigned int	ClapTrap::_class_attack_damage = 0;

void ClapTrap::attack(std::string const & target)
{
	std::string		name = this->_name;
	unsigned int	current_energy_points = this->_energy_points;
	unsigned int	dmg = this->_attack_damage;
	std::string		class_name = this->_class_name;

	if (this->_hitpoints == 0)
	{
		std::cout << class_name << " " << name << " is dead\n";
		return ;
	}
	if (current_energy_points >= 1)
	{
		std::cout << class_name << " " << name << " attacks " << target << " causing " << dmg << " points of damage!\n";
		std::cout << "This attack cost " << class_name << " " << name << " " << 1 << " energy points left\n";
		this->_energy_points -= 1;
	}
	else
	{
		std::cout << class_name << " " << name << " can't attack " << target << std::endl;
	}
	std::cout << class_name << " " << name << " has " << this->_energy_points << " energy points\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::string		name = this->_name;
	std::string		class_name = this->_class_name;

	if (this->_hitpoints == 0)
	{
		std::cout << class_name << " " << name << " is dead\n";
		return ;
	}
	std::cout << class_name << " " << name << " just got hit and received " << amount << " points of damage!\n";
	if (amount > this->_hitpoints)
		this->_hitpoints = 0;
	else
		this->_hitpoints -= amount;
	std::cout << class_name << " " << name << " has " << this->_hitpoints << " hit point\n";
	if (this->_hitpoints == 0)
		std::cout << class_name << " " << name << " is dead\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::string		name = this->_name;
	unsigned int	max_hp = this->_max_hp;
	std::string		class_name = this->_class_name;

	if (this->_hitpoints == 0)
	{
		std::cout << class_name << " " << name << " is dead\n";
		return ;
	}
	else if (this->_energy_points <= 0)
	{
		std::cout << class_name << " " << name << " has no energy\n";
		return ;
	}
	std::cout << class_name << " " << name << " was repaired for " << amount << " points of damage!\n";
	this->_energy_points -= 1;
	if (this->_hitpoints + amount >= max_hp)
	{
		this->_hitpoints = max_hp;
		std::cout << class_name << " " << name << " is now fully healed!\n";
	}
	else
		this->_hitpoints += amount;
	std::cout << class_name << " " << name << " has " << this->_hitpoints << " hit point\n";
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

std::string ClapTrap::get_name( void ) const
{
	return (this->_name);
}

unsigned int ClapTrap::get_hitpoints( void ) const
{
	return (this->_hitpoints);
}

unsigned int ClapTrap::get_energy_points( void ) const
{
	return (this->_energy_points);
}

unsigned int ClapTrap::get_attack_damage( void ) const
{
	return (this->_attack_damage);
}

unsigned int ClapTrap::get_class_hp( void )
{
	return (ClapTrap::_class_hp);
}

unsigned int ClapTrap::get_class_energy_points( void )
{
	return (ClapTrap::_class_energy_points);
}

unsigned int ClapTrap::get_class_attack_damage( void )
{
	return (ClapTrap::_class_attack_damage);
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	this->_class_name = "Claptrap";
	this->_max_hp = 10;
	this->_attack_damage = this->_class_attack_damage;
	this->_energy_points = this->_class_energy_points;
	this->_hitpoints = this->_class_hp;
	
	std::string		class_name = this->_class_name;

	std::cout << class_name << " "  << this->_name << " has been created\n";
}

ClapTrap::ClapTrap(const ClapTrap & src)
{
	std::string 	name;
	std::string		class_name = this->_class_name;

	name = src.get_name() + "copy";
	this->set_name(name);
	this->_class_name = "Claptrap";
	this->_max_hp = 10;
	this->_attack_damage = this->get_class_attack_damage();
	this->_energy_points = this->get_class_energy_points();
	this->_hitpoints = this->get_class_hp();
	std::cout << class_name << " copy "  << this->_name << " has been created\n";
}

ClapTrap::ClapTrap(std::string name, std::string class_name, unsigned int max_hp)
{
	this->_name = name;
	this->_class_name = class_name;
	this->_max_hp = max_hp;
	this->_attack_damage = this->_class_attack_damage;
	this->_energy_points = this->_class_energy_points;
	this->_hitpoints = this->_class_hp;

	std::cout << "Claptrap " << this->_name << " has been created\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap " << this->_name << " is now destroyed...\n";
}

ClapTrap & ClapTrap::operator=(const ClapTrap & rhs)
{
	this->_class_name = "Claptrap";
	this->_max_hp = 10;
	this->set_name(rhs.get_name());
	this->_attack_damage = rhs.get_attack_damage();
	this->_energy_points = rhs.get_energy_points();
	this->_hitpoints = rhs.get_hitpoints();
	return (*this);
}