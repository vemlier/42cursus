/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:26:09 by chukim            #+#    #+#             */
/*   Updated: 2022/11/01 09:54:18 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <stdint.h>
#include "Data.hpp"

static uintptr_t serialize(Data* ptr)
{
	return	(reinterpret_cast<uintptr_t>(ptr));
}

static Data* deserialize(uintptr_t raw)
{
	return	(reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data	data1("my data");

	// serialize
	uintptr_t	test = serialize(&data1);

	// deserialize
	Data	*data2 = deserialize(test);
	std::cout << std::endl << std::endl;

	std::cout << "ADRESSES COMPARED:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "Data1 address: "<< &data1 << std::endl;
	std::cout << "Data2 address: "<< data2 << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "VALUES INSIDE DATA COMPARED:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "Data1 value: " << data1.getValue() << std::endl;
	std::cout << "Data2 value: " << (*data2).getValue() << std::endl;
	std::cout << std::endl << std::endl;

	return (0);
}
