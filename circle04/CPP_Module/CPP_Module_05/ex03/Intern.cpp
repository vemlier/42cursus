/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:23:37 by chukim            #+#    #+#             */
/*   Updated: 2022/11/01 07:33:55 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "An Intern constructed\n";
}

Intern::~Intern()
{
	std::cout << "An Intern destroyed\n";
}

Intern::Intern(Intern const & ref)
{
	(void)ref;
	std::cout << "An Intern constructed as a copy\n";
}

Intern & Intern::operator=(Intern const & ref)
{
	(void)ref;
	return (*this);
}

static Form	*new_robo(std::string target)
{
	Form	*robo = new RobotomyRequestForm(target);
	return (robo);
}

static Form	*new_president(std::string target)
{
	Form	*president = new PresidentialPardonForm(target);
	return (president);
}

static Form	*new_shrub(std::string target)
{
	Form	*shrub = new ShrubberyCreationForm(target);
	return (shrub);
}

Form *Intern::makeForm(std::string form_name, std::string form_target)
{
	Form	*(*fct[3])(std::string target) = {new_robo, new_president, new_shrub};
	std::string	msg[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	Form	*ret = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (form_name == msg[i])
			ret = fct[i](form_target);
	}
	if (ret)
	{
		std::cout << "Intern creates " << ret->getName() << std::endl;
		std::cout << *ret << std::endl; 
	}
	else
		throw (Intern::Exception());
	return (ret);
}

const char* Intern::Exception::what() const throw()
{
	return ("Unknown Form exception");
}
