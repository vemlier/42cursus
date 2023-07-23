/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:23:45 by chukim            #+#    #+#             */
/*   Updated: 2022/11/01 07:41:23 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::srand(std::time(0));

	Intern	intern;
	Form	*robo_form;
	Form	*shrub_form;
	Form	*president_form;
	Form	*unknown_form;
	Bureaucrat	chu("chu", 1);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Intern" << std::endl;
	std::cout << "--------------------" << std::endl;

	// Robo
	robo_form = intern.makeForm("robotomy request", "Bender");
	std::cout << robo_form->getName() << " was just created " << std::endl << std::endl;

	// President
	president_form = intern.makeForm("presidential pardon", "Prisoner");
	std::cout << president_form->getName() << " was just created " << std::endl << std::endl;

	// Shrub
	shrub_form = intern.makeForm("shrubbery creation", "Host");
	std::cout << shrub_form->getName() << " was just created " << std::endl << std::endl;
	shrub_form->be_signed(chu);
	chu.executeForm(*shrub_form);

	// killing
	try
	{
		unknown_form = intern.makeForm("killing license", "Murderer");
		std::cout << *unknown_form << " was just created " << std::endl << std::endl;
	}
	catch (Intern::Exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "Destructor" << std::endl;
	std::cout << "--------------------" << std::endl;
	delete robo_form;
	delete shrub_form;
	delete president_form;
	std::cout << "--------------------" << std::endl;
	
	std::cout << std::endl;
	//system("leaks ex03");
	return (0);
}
