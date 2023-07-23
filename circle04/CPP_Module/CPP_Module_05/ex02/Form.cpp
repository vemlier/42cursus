/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:22:38 by chukim            #+#    #+#             */
/*   Updated: 2022/11/01 07:27:16 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form() : _name("Default"), _grade_to_sign(150), _grade_to_execute(150), _signed(0)
{
	std::cout << "A default " << _name << " constructed" << std::endl;
}

Form::~Form()
{
	std::cout << _name << " destroyed\n";
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _signed(0)
{
	if (_grade_to_sign > 150 || _grade_to_execute > 150)
		throw (Form::GradeTooLowException());
	else if (_grade_to_sign < 1 || _grade_to_execute < 1)
		throw (Form::GradeTooHighException());
	else
		std::cout << _name << " constructed" << std::endl;
}

Form::Form(Form const & ref) : _name(ref.getName()), _grade_to_sign(ref.getGradeToSign()), _grade_to_execute(ref.getGradeToExecute()), _signed(ref.getSigned())
{
	std::cout << _name << " constructed as a copy" << std::endl;
}

Form & Form::operator=(Form const & ref)
{
	this->_signed = ref.getSigned();
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
	o << "Form " << rhs.getName() << "\ngrade_to_sign : " << rhs.getGradeToSign() << "\ngrade_to_execute : "
		<< rhs.getGradeToExecute() << "\nsigned : " << rhs.getSigned() << std::endl;
	return (o);
}

const std::string	Form::getName(void) const
{
	return (this->_name);
}

int	Form::getGradeToSign(void) const
{
	return (this->_grade_to_sign);
}

int	Form::getGradeToExecute(void) const
{
	return (this->_grade_to_execute);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

void	Form::setSigned(const bool new_value)
{
	std::cout << _name << " signed value was set to " << new_value << std::endl;
	this->_signed = new_value;
}

const char* Form::Exception::what() const throw()
{
	return ("FormException");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("the grade is too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("the grade is too high");
}

const char* Form::UnsignedFormException::what() const throw()
{
	return ("Cannot execute an unsigned form");
}

void	Form::be_signed(Bureaucrat & ref)
{
	int	grade = ref.getGrade();

	if (grade > _grade_to_sign)
	{
		throw (Form::GradeTooLowException());
		return ;
	}
	_signed = true;
	std::cout << _name << " was just signed by the bureaucrat " << ref.getName() << " with a grade " << ref.getGrade() << std::endl;
}
