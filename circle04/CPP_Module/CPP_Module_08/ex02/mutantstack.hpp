/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:54:27 by chukim            #+#    #+#             */
/*   Updated: 2022/11/28 07:00:50 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator 
			iterator;
		typedef typename std::stack<T>::container_type::const_iterator
			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator
			reverse_iterator;	
		typedef typename std::stack<T>::container_type::const_reverse_iterator
			const_reverse_iterator;

		iterator begin(void)
		{
			return this->c.begin();
		}

		iterator end(void)
		{
			return this->c.end();
		}

		const_iterator cbegin(void) const
		{
			return this->c.cbegin();
		}

		const_iterator cend(void) const
		{
			return this->c.cend();
		}

		reverse_iterator rbegin(void)
		{
			return this->c.rbegin();
		}

		reverse_iterator rend(void)
		{
			return this->c.rend();
		}

		const_reverse_iterator crbegin(void) const
		{
			return this->c.crbegin();
		}

		const_reverse_iterator crend(void) const
		{
			return this->c.crend();
		}

		MutantStack(void) {}
		MutantStack(MutantStack const & m) { *this = m; }
		~MutantStack(void) {}
		MutantStack& operator=(MutantStack const & m)
		{
			if (this != &m)
				std::stack<T>::operator=(m);
			return (*this);
		}
};

#endif
