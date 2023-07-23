/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:38:48 by chukim            #+#    #+#             */
/*   Updated: 2022/11/28 06:56:27 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int cpapcity) : _capacity(cpapcity)
{
	_vector.reserve(cpapcity);
	_size = 0;
	std::cout << "Span has been constructed" << std::endl;
}

Span::~Span()
{
	std::cout << "Span has been destroyed" << std::endl;
}

Span::Span(Span const &ref) : _capacity(ref._capacity), _vector(ref._vector)
{
	_size = ref._vector.size();
	std::cout << "Span has been constructed by copy" << std::endl;
}

Span const &Span::operator=(Span const &ref)
{
	this->_capacity = ref._capacity;
	this->_vector = ref._vector;
	this->_size = ref._vector.size();
	std::cout << "Assignement operator called" << std::endl;
	return (*this);
}

Span::Span(int first, int last, int jump)
{
	int f, l;
	if (last > first)
	{
		f = first;
		l = last;
	}
	else
	{
		f = last;
		l = first;
	}
	_capacity = std::abs((last - first) / jump);
	_vector.reserve(_capacity);
	for (int i = f; i < l; i += jump)
		_vector.push_back(i);
	_size = _capacity;
	std::cout << "Span has been constructed with range" << std::endl;
}

unsigned int Span::getNInts(void) const
{
	return (_capacity);
}

unsigned int Span::getNContents(void) const
{
	return (_size);
}

std::vector<int> Span::getVector(void) const
{
	return (_vector);
}

void Span::addNumber(int n)
{
	if (_vector.size() >= _capacity || _size >= _capacity)
		throw(std::out_of_range("Cannot add more elements"));
	_vector.push_back(n);
	_size++;
}

void Span::addNumber(my_iter start, my_iter end)
{
	// Avoid infinite loop
	if (end < start)
		return ;
	for (my_iter i = start; i != end; i++)
		addNumber(*i);
}

int Span::longestSpan(void)
{
	if (_size == 0 || _size == 1)
		throw(std::out_of_range("Not enough elements for a span"));
	std::vector<int>::iterator min = std::min_element(_vector.begin(), _vector.end());
	std::vector<int>::iterator max = std::max_element(_vector.begin(), _vector.end());
	int longest_span = *max - *min;
	return (longest_span);
}

int Span::shortestSpan(void)
{
	if (_size == 0 || _size == 1)
		throw(std::out_of_range("Not enough elements for a span"));
	std::vector<int>::iterator max = std::max_element(_vector.begin(), _vector.end());
	int shortest_span = *max;

	std::vector<int> v = _vector;
	std::sort(v.begin(), v.end());
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (i != 0 && std::abs(v[i] - v[i - 1]) < shortest_span)
			shortest_span = std::abs(v[i] - v[i - 1]);
	}
	return (shortest_span);
}

std::ostream & operator<<( std::ostream & o, Span const & rhs)
{
	std::cout << "Span contents: ";
	for (unsigned int i = 0; i < rhs.getNContents(); i++)
		std::cout << (rhs.getVector())[i] << " ";
	std::cout << std::endl;
	return (o);
}
