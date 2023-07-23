/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:48:31 by chukim            #+#    #+#             */
/*   Updated: 2022/10/25 10:27:36 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::string s1 = "chu";
	std::string s2 = "kim";

	ClapTrap claptrap1(s1);
	ClapTrap claptrap2(s2);
	std::cout << std::endl;

	claptrap1.attack(s2);
	claptrap2.takeDamage(2);
	claptrap2.beRepaired(3);
	claptrap2.attack(s1);
	claptrap1.takeDamage(0);
	claptrap1.beRepaired(18);
	claptrap1.takeDamage(11);
	claptrap1.beRepaired(11);
	claptrap2.takeDamage(3);
	claptrap2.beRepaired(4);
	std::cout << std::endl;
	return (0);
}