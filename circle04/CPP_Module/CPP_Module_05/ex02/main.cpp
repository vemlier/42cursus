/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:22:46 by chukim            #+#    #+#             */
/*   Updated: 2022/11/01 07:26:20 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::srand(std::time(0));

	std::cout << std::endl;

	std::cout << "Constructor" << std::endl;
	std::cout << "--------------------" << std::endl;
	Bureaucrat				chu("chu", 1);
	Bureaucrat				kim("kim", 140);
	ShrubberyCreationForm	shrub("shrub");
	RobotomyRequestForm		robo("robo");
	PresidentialPardonForm	president("president");
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "shrub" << std::endl;
	std::cout << "--------------------" << std::endl;	
	std::cout << "UNSIGNED" << std::endl;
	chu.executeForm(shrub);
	shrub.be_signed(chu);

	std::cout << "SIGNED" << std::endl;
	chu.executeForm(shrub);
	std::cout << std::endl;

	std::cout << "too low" << std::endl;
	kim.executeForm(shrub);
	std::cout << "--------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "robo" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "UNSIGNED" << std::endl;
	chu.executeForm(robo);
	robo.be_signed(chu);

	std::cout << "SIGNED" << std::endl;
	chu.executeForm(robo);
	chu.executeForm(robo);
	chu.executeForm(robo);
	chu.executeForm(robo);
	chu.executeForm(robo);
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "president" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "UNSIGNED" << std::endl;
	chu.executeForm(president);
	president.be_signed(chu);

	std::cout << "SIGNED" << std::endl;
	chu.executeForm(president);
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	return (0);
}
