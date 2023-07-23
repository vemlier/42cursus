/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:38:56 by chukim            #+#    #+#             */
/*   Updated: 2022/11/17 12:12:02 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int			iarr[4] = {0, 1, 2, 3};
	char		carr[5] = "abcd";
	float		farr[4] = {1.1f, 2.2f, 3.3f, 4.4f};
	std::string	sarr[4] = {"frist string", "second string", "third string", "fourth string"};

	// INT
	tests(iarr, 4, "INT");

	// CHAR
	tests(carr, 5, "CHAR");

	// FLOAT
	tests(farr, 4, "FLOAT");

	// STRING
	tests(sarr, 4, "STRING");
	return (0);
}
