/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:38:41 by chukim            #+#    #+#             */
/*   Updated: 2022/11/28 06:58:06 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main(void)
{
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << sp;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;

	Span	sp1(1, 10, 1);
	std::cout << sp1;
	std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << sp1.longestSpan() << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;

	Span	sp2(1, 100000, 10);
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << sp2.longestSpan() << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;

	Span	sp3 = Span(30);
	my_iter a, b;
	a = sp1.getVector().begin();
	b = sp1.getVector().end();
	sp3.addNumber(a, b);
	sp3.addNumber(a, b);
	std::cout << sp3;
	std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << sp3.longestSpan() << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;

	Span	sp4(0);
	std::cout << sp4;
	try
	{
		sp4.addNumber(5);
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		sp4.shortestSpan();
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		sp4.longestSpan();
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------" << std::endl;
	return (0);
}
