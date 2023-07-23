/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:02:18 by chukim            #+#    #+#             */
/*   Updated: 2023/07/20 13:22:33 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <list>
# include <algorithm>

class PmergeMe
{
	private:
		std::deque<int> _dequeUnsorted;
		std::deque<std::pair<int, int> > _dequePairs;
		std::deque<int> _dequeSorted;
		std::list<int> _listUnsorted;
		std::list<std::pair<int, int> > _listPairs;
		std::list<int> _listSorted;

	public:
		PmergeMe(int ac, char **av);
		void display_deque(const std::deque<int>& container);
		void display_list(const std::list<int>& container);
		void mergeInsertSortDeque();
		void mergeInsertSortList();
};
#endif
