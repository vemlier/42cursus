/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:01:53 by chukim            #+#    #+#             */
/*   Updated: 2023/07/20 08:38:09 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &var)
{
	*this = var;
}

RPN &RPN::operator=(const RPN &var)
{
	_numbers = var._numbers;
	return (*this);
}

void RPN::calculate(std::string input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		char c = input[i];
		if (c == ' ')
		{
			continue;
		}
		else if (isdigit(c))
		{
			int number = c - '0';
			_numbers.push(number);
		}
		else if (c == '+' && _numbers.size() >= 2)
		{
			double b = _numbers.top();
			_numbers.pop();
			double a = _numbers.top();
			_numbers.pop();
			_numbers.push(a + b);
		}
		else if (c == '-' && _numbers.size() >= 2)
		{
			double b = _numbers.top();
			_numbers.pop();
			double a = _numbers.top();
			_numbers.pop();
			_numbers.push(a - b);
		}
		else if (c == '*' && _numbers.size() >= 2)
		{
			double b = _numbers.top();
			_numbers.pop();
			double a = _numbers.top();
			_numbers.pop();
			_numbers.push(a * b);
		}
		else if (c == '/' && _numbers.size() >= 2)
		{
			double b = _numbers.top();
			_numbers.pop();
			double a = _numbers.top();
			_numbers.pop();
			_numbers.push(a / b);
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return;
		}
	}

	if (_numbers.size() == 1)
	{
		double result = _numbers.top();
		_numbers.pop();
		if (isnan(result) || isinf(result))
		{
			std::cout << "Error: result is not a number.";
			return ;
		}
		std::cout << result << std::endl;
	}
	else
	{
		std::cerr << "Error" << std::endl;
	}
}
