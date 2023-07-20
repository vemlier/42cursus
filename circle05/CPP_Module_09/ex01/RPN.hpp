/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:01:59 by chukim            #+#    #+#             */
/*   Updated: 2023/07/20 08:38:03 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>

class RPN
{
private:
	std::stack<double> _numbers;

public:
	RPN();
	~RPN();
	RPN(const RPN &var);
	RPN &operator=(const RPN &var);

	void calculate(std::string input);
};
#endif
