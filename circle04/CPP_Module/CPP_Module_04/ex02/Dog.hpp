/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:52:34 by chukim            #+#    #+#             */
/*   Updated: 2022/10/29 12:59:43 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
	private:
		Brain		*brain;

	public:
		Dog();
		~Dog();
		Dog(const Dog & ref);
		Dog & operator=(const Dog & rhs);
		void makeSound() const;
		Brain *getBrain(void) const;
};

#endif