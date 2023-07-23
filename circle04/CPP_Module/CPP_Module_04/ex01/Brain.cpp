/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:51:06 by chukim            #+#    #+#             */
/*   Updated: 2022/10/29 14:52:27 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "ideas";
	std::cout << "A brain constructed\n";
}

Brain::~Brain()
{
	delete [] (this->ideas);
	std::cout << "A brain destroyed\n";
}

Brain::Brain(const Brain & ref)
{
	std::string *ref_ideas = ref.getIdeas();
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ref_ideas[i];
	std::cout << "A copied brain constructed\n";
}

Brain & Brain::operator=(const Brain & rhs)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	return (*this);
}

std::string *Brain::getIdeas() const
{
	return (this->ideas);
}