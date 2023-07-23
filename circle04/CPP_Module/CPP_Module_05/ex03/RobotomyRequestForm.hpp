/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:24:31 by chukim            #+#    #+#             */
/*   Updated: 2022/11/01 07:34:14 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class Form;

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const & ref);
		RobotomyRequestForm & operator=(RobotomyRequestForm const & ref);
		
		std::string	getTarget(void) const;
		void execute(Bureaucrat const & executor) const;

		class FailureException : public Form::Exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		std::string	_target;
};

#endif
