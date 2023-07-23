/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:52:24 by chukim            #+#    #+#             */
/*   Updated: 2022/10/29 12:59:39 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
{
	private:
		Brain		*brain;

	public:
		Cat();
		~Cat();
		Cat(const Cat & ref);
		Cat & operator=(const Cat & rhs);
		void makeSound() const;
		Brain *getBrain(void) const;
};

#endif