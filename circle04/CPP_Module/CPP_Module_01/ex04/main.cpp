/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:23:24 by chukim            #+#    #+#             */
/*   Updated: 2022/10/13 13:30:31 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc != 4 || !argv[2][0] || !argv[3][0])
	{
		std::cout << "Arguments error" << std::endl;
		return (-1);
	}
	
	std::ifstream	ifs(argv[1]);
	if (!ifs.is_open())
	{
		std::cout << "Coulnd't open the input file" << std::endl;
		return (-1);
	}
	std::string	file_name = (std::string)argv[1] + ".replace";
	std::ofstream	ofs(file_name);
	if (!ofs.is_open())
	{
		std::cout << "Coulnd't open the output file" << std::endl; 
		return (-1);
	}
	std::string	line;
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	
	while (getline(ifs, line))
	{
		int start = 0;
		while (true)
		{
			size_t i = line.find(s1, start);
			if (i == std::string::npos)
				break ;
			ofs << line.substr(start, i - start) << s2;
			start = i + s1.length();
		}
		ofs << &line[start] << std::endl;
	}
	ofs.close();
	ifs.close();
}