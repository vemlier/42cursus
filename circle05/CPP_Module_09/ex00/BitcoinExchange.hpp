/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:30:30 by chukim            #+#    #+#             */
/*   Updated: 2023/07/20 07:31:22 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <vector>

class Btc
{
	private:
		std::map <std::string, float> _data;
		int _readFlag;

	public:
		Btc();
		~Btc();
		Btc(Btc const &ref);
		Btc& operator=(Btc const &ref);

		void setData(std::string date, float value);

		std::map<std::string, float> getData();

		std::vector<std::string> splitString(std::string str, char delimiter);

		void readInput(std::string inputPath);
};
#endif
