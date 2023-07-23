/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:22:16 by chukim            #+#    #+#             */
/*   Updated: 2022/11/01 07:24:46 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "Constructor" << std::endl;
	std::cout << "--------------------" << std::endl;
	Bureaucrat	chu("chu", 1);
	Bureaucrat	kim("kim", 132);

	Bureaucrat chu_ref(chu);
	Bureaucrat & kim_ref = kim;

	Form	a("a", 4, 6);
	Form	b("b", 146, 135);
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "too low" << std::endl;
	std::cout << "--------------------" << std::endl;
	try
	{
		Form	c("c", 150, 151);
	}
	catch (Form::Exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "too high" << std::endl;
	std::cout << "--------------------" << std::endl;
	try
	{
		Form	c("c", -1, 1);
	}
	catch (Form::Exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "forms" << std::endl;
	std::cout << "--------------------" << std::endl;
	chu_ref.signForm(a);
	std::cout << a;
	a.setSigned(false);
	std::cout << std::endl;

	kim_ref.signForm(a);
	std::cout << a;
	std::cout << "--------------------" << std::endl;
	return (0);	
}
