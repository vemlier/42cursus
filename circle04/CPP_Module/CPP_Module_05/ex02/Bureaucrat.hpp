/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:22:32 by chukim            #+#    #+#             */
/*   Updated: 2022/11/01 07:26:05 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat & ref);
		Bureaucrat & operator=(const Bureaucrat & ref);

		void	incrementGrade(void);
		void	decrementGrade(void);

		const std::string	getName(void) const;
		int					getGrade(void) const;

		void				setGrade(const int new_grade);

		class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public Bureaucrat::Exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooHighException : public Bureaucrat::Exception
		{
			public:
				virtual const char* what() const throw();
		};

		void signForm(Form & ref);

		void executeForm(Form const & form);

	private:
		const std::string	_name;
		int					_grade;

};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs);


#endif
