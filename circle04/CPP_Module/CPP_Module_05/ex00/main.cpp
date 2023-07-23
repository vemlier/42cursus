/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:21:09 by chukim            #+#    #+#             */
/*   Updated: 2022/11/01 07:18:13 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << std::endl;
	std::cout << "Grade -1" << std::endl;
	std::cout << "--------------------" << std::endl;
	try
	{
		Bureaucrat chukim("chukim", -1);
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;
	
	std::cout << "Gade 151" << std::endl;
	std::cout << "--------------------" << std::endl;
	try
	{
		Bureaucrat chukim("chukim", 151);
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "Increment and decrement" << std::endl;
	std::cout << "--------------------" << std::endl;
	Bureaucrat kimchu("kimchu", 1);
	try
	{
		kimchu.decrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << kimchu << std::endl;
	try
	{
		kimchu.incrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << kimchu << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Increment at 1" << std::endl;
	std::cout << "--------------------" << std::endl;
	try
	{
		kimchu.incrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Decrement at 150" << std::endl;
	std::cout << "--------------------" << std::endl;
	kimchu.setGrade(150);
	try
	{
		kimchu.decrementGrade();
	}
	catch (Bureaucrat::Exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------" << std::endl;

	return (0);
}
