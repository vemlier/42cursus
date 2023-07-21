/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:32:40 by chukim            #+#    #+#             */
/*   Updated: 2023/07/21 23:24:22 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <ctime>

const char* WHITESPACE = " \t\n\r";

static std::string& ltrim(std::string& s)
{
	s.erase(0, s.find_first_not_of(WHITESPACE));
	return s;
}

static std::string& rtrim(std::string& s)
{
	s.erase(s.find_last_not_of(WHITESPACE) + 1);
	return s;
}

static std::string& trim(std::string& s)
{
	return ltrim(rtrim(s));
}

static double string_to_double(const std::string& str)
{
	double result;
	std::stringstream ss(str);
	ss >> result;
	return result;
}

Btc::Btc()
{
	int i = 0;
	_readFlag = 1;
	std::ifstream file;
	file.open("data.csv");
	if (!file.is_open())
	{
		_readFlag = 0;
		return;
	}
	std::string line;
	while(std::getline(file, line))
	{
		if (i == 0)
		{
			i = 1;
			continue;
		}
		size_t pos = line.find(',');
		if (pos == std::string::npos)
		{
			std::cout << "Error : Invalid Paramter" << std::endl;
			continue;
		}
		std::string date = line.substr(0, pos);
		double value;
		try
		{
			value = string_to_double(line.substr(pos + 1));
		}
		catch (std::exception &e)
		{
			(void)e;
			std::cout << "Error: could not parse value" << std::endl;
			continue;
		}
		setData(date, value);
	}
	file.close();
}

Btc::~Btc()
{
}

Btc::Btc(Btc const &ref)
{
	*this = ref;
}

Btc &Btc::operator=(Btc const &ref)
{
	_data = ref._data;
	return (*this);
}

void Btc::setData(std::string date, float value)
{
	_data.insert(std::make_pair(date, value));
}

std::map<std::string, float> Btc::getData()
{
	return (_data);
}

std::vector<std::string> Btc::splitString(std::string str, char delimiter)
{
	std::vector<std::string> substrings;
	std::string substring = "";
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != delimiter)
		{
			substring += str[i];
		}
		else
		{
			substrings.push_back(substring);
			while (str[i] == delimiter)
				i++;
			i--;
			substring = "";
		}
	}
	substrings.push_back(substring);
	return substrings;
}

void Btc::readInput(std::string inputPath)
{
	int i = 0;
	std::ifstream file2;
	file2.open(inputPath.c_str());
	if (!file2.is_open())
	{
		_readFlag = -1;
		return;
	}
	std::string line;
	std::vector<std::string> vectorLine;
	while(std::getline(file2, line))
	{
		if (i == 0)
		{
			i = 1;
			continue;
		}
		vectorLine = splitString(line, '|');
		std::tm dateStruct = {};
		if (strptime(vectorLine[0].c_str(), "%Y-%m-%d", &dateStruct) == NULL)
		{
			std::cout << "Error: bad input => " << vectorLine[0] << std::endl;
			continue;
		}
		if (vectorLine[1].length() == 0 || vectorLine.size() < 2)
		{
			std::cout << "Error: bad input => " << vectorLine[0] << std::endl;
			continue;
		}
		std::map<std::string, float>::iterator it = _data.upper_bound(trim(vectorLine[0]));
		if (it != _data.end())
		{
			std::pair<std::string, float> p;
			if (it->first == _data.begin()->first)
				p = *(it);
			else
				p = *(--it);
			try
			{
				if (string_to_double(vectorLine[1]) > 1000)
					std::cout << "Error: too large a number." << std::endl;
				else if (string_to_double(vectorLine[1]) < 0)
					std::cout << "Error: not a positive number." << std::endl;
				else
					std::cout << vectorLine[0] << " =>" << vectorLine[1] << " = " << string_to_double(vectorLine[1]) * p.second << std::endl;

			}
			catch (const std::exception &e)
			{
				(void)e;
				std::cout << "Error : Input Not A Number" << std::endl;
				continue;
			}
		}
	}
	file2.close();
}
