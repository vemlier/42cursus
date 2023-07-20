/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:02:14 by chukim            #+#    #+#             */
/*   Updated: 2023/07/20 21:00:12 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

PmergeMe::PmergeMe(int ac, char* av[])
{
	srand(time(NULL));
	for (int i = 1; i < ac; ++i)
	{
		int value = atoi(av[i]);
		if (value <= 0)
		{
			std::cout << "Error" << std::endl;
			exit(1);
		}
		_dequeUnsorted.push_back(value);
		_listUnsorted.push_back(value);
	}
	std::cout << "Before: ";
	display_deque(_dequeUnsorted);

	clock_t start1 = clock();
	mergeInsertSortDeque();
	clock_t end1 = clock();
	double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

	clock_t start2 = clock();
	mergeInsertSortList();
	clock_t end2 = clock();
	double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

	std::cout << "After[Deque]: ";
	display_deque(_dequeSorted);
	std::cout << "After[List]: ";
	display_list(_listSorted);
	std::cout << "Time to process a range of " << _dequeSorted.size() << " elements with std::deque : " << time1 << " us" << std::endl;
	std::cout << "Time to process a range of " << _listSorted.size() << " elements with std::list : " << time2 << " us" << std::endl;
}

void PmergeMe::display_deque(const std::deque<int>& container)
{
	std::deque<int>::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::display_list(const std::list<int>& container)
{
	std::list<int>::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::mergeInsertSortDeque()
{
	for (size_t i = 0; i < _dequeUnsorted.size(); i++)
	{
		if (i == 0 && _dequeUnsorted.size() % 2)
			_dequePairs.push_back(std::make_pair(-1, _dequeUnsorted[i]));
		else
		{
			_dequePairs.push_back(std::make_pair(_dequeUnsorted[i], _dequeUnsorted[i + 1]));
			i = i + 1;
		}
	}

	for (std::deque<std::pair<int, int> >::iterator it = _dequePairs.begin(); it != _dequePairs.end(); ++it)
	{
		if ((*it).first < (*it).second)
			std::swap((*it).first, (*it).second);
	}

	for (std::deque<std::pair<int, int> >::iterator it = _dequePairs.begin() + 1; it != _dequePairs.end(); ++it)
	{
		std::deque<std::pair<int, int> >::iterator actual = it;
		std::deque<std::pair<int, int> >::iterator prev = it - 1;
		while ((*actual).first < (*prev).first)
		{
			std::swap(*actual, *prev);
			if (prev != _dequePairs.begin())
			{
				actual = prev;
				prev = actual - 1;
			}
		}
	}

	for (std::deque<std::pair<int, int> >::iterator it = _dequePairs.begin(); it != _dequePairs.end(); ++it)
	{
		if ((*it).first != -1)
			_dequeSorted.push_back((*it).first);
	}

	for (std::deque<std::pair<int, int> >::iterator it = _dequePairs.begin(); it != _dequePairs.end(); ++it)
	{
		std::deque<int>::iterator itSorted;
		itSorted = std::lower_bound(_dequeSorted.begin(), find(_dequeSorted.begin(), _dequeSorted.end(), (*it).first), (*it).second);
		_dequeSorted.insert(itSorted, (*it).second);
	}
	if (_dequeSorted[0] == -1)
		_dequeSorted.pop_front();
}

void PmergeMe::mergeInsertSortList()
{
	for (std::list<int>::iterator it = _listUnsorted.begin(); it != _listUnsorted.end(); ++it)
	{
		if (it == _listUnsorted.begin() && _listUnsorted.size() % 2)
			_listPairs.push_back(std::make_pair(-1, *it));
		else
		{
			std::list<int>::iterator next = it;
			next++;
			_listPairs.push_back(std::make_pair(*it, *next));
			++it;
		}
	}

	for (std::list<std::pair<int, int> >::iterator it = _listPairs.begin(); it != _listPairs.end(); ++it)
	{
		if ((*it).first < (*it).second)
			std::swap((*it).first, (*it).second);
	}
	std::list<std::pair<int, int> >::iterator it2 = _listPairs.begin();
	++it2;
	for (std::list<std::pair<int, int> >::iterator it = it2; it != _listPairs.end(); ++it)
	{
		std::list<std::pair<int, int> >::iterator actual = it;
		std::list<std::pair<int, int> >::iterator prev = it;
		--prev;
		while ((*actual).first < (*prev).first)
		{
			std::swap(*actual, *prev);
			if (prev != _listPairs.begin())
			{
				actual = prev;
				prev = actual;
				--prev;
			}
		}
	}

	for (std::list<std::pair<int, int> >::iterator it = _listPairs.begin(); it != _listPairs.end(); ++it)
	{
		if ((*it).first != -1)
			_listSorted.push_back((*it).first);
	}

	for (std::list<std::pair<int, int> >::iterator it = _listPairs.begin(); it != _listPairs.end(); ++it)
	{
		std::list<int>::iterator itSorted = std::lower_bound(_listSorted.begin(), find(_listSorted.begin(), _listSorted.end(), (*it).first), (*it).second);
		_listSorted.insert(itSorted, (*it).second);
	}
	if (_listSorted.front() == -1)
		_listSorted.pop_front();
}
