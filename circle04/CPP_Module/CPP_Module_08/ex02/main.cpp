/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:51:51 by chukim            #+#    #+#             */
/*   Updated: 2022/11/28 06:51:14 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int main()
{
	std::cout << "--------------------" << std::endl << std::endl;
	MutantStack<int> mstack;
	mstack.push(5); 
	mstack.push(17);

	std::cout << "Top : " << mstack.top() << std::endl;
	
	mstack.pop();

	std::cout << "Size : " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(-42);
	mstack.push(0);
	mstack.push(333);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	std::cout << "--------------------" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl << std::endl;

	std::cout << "CHARS:" << std::endl;
	std::cout << "------------------------------------------------" << std::endl << std::endl;
	MutantStack<char>	mcstack;
	mcstack.push('A'); 
	mcstack.push('B');
	std::cout << "Top : " << mcstack.top() << std::endl;
	mcstack.pop();
	std::cout << "Size : " << mcstack.size() << std::endl;
	mcstack.push('C');
	mcstack.push('D');
	mcstack.push('E');
	mcstack.push('F');
	mcstack.push('G');
	MutantStack<char>::iterator it2 = mcstack.begin();
	MutantStack<char>::iterator it2e = mcstack.end();
	++it2;
	--it2;
	std::cout << "--------------------" << std::endl;
	while (it2 != it2e)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	return 0;
}
