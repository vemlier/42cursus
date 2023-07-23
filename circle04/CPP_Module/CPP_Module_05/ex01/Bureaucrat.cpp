/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:21:45 by chukim            #+#    #+#             */
/*   Updated: 2022/11/01 07:25:07 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "A Bureaucrat constructed\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
	{
		this->_grade = grade;
		std::cout << "A Bureaucrat " << _name << " constructed " << "with a grade " << _grade << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A Bureaucrat " << _name << " destroyed " << "with a grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat & ref) : _name(ref.getName())
{
	this->_grade = ref.getGrade();
	std::cout << "A Bureaucrat " << _name << " constructed " << "with a grade " << _grade << " as a copy\n";
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & ref)
{
	this->_grade = ref.getGrade();
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << "Bureaucrat " << rhs.getName() << " has a grade " << rhs.getGrade() << std::endl;
	return (o);
}

void	Bureaucrat::incrementGrade(void)
{
	std::cout << "Bureaucrat " << _name << "'s grade " << _grade << " increases by 1\n";
	if (this->_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	std::cout << "Bureaucrat " << _name << "'s grade " << _grade << " decreases by 1\n";
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
	{
		this->_grade++;
	}
}

const std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade( const int new_grade)
{
	this->_grade = new_grade;
	std::cout << "Bureaucrat " << _name << "'s grade is " << new_grade << std::endl;
}

// ---------------------- Exception Functions -----------------------

const char* Bureaucrat::Exception::what() const throw()
{
	return ("BureaucratException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

// ---------------------- Exception Functions -----------------------

void Bureaucrat::signForm(Form & ref)
{
	try
	{
		ref.be_signed(*this);
		std::cout << "Bureaucrat " << this->_name << " with a grade " << this->_grade << " succesfully signs " << ref.getName() << std::endl;
	}
	catch (Form::Exception &e)
	{
		std::cout << "Bureaucrat " << this->_name << " with a grade " << this->_grade << " cannot sign " << ref.getName() << " because " << e.what() << std::endl;
	}
}
