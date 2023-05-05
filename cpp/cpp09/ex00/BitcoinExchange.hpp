//
// Created by Price Skip on 4/11/23.
//

#ifndef EX00_BITCOINEXCHANGE_HPP
#define EX00_BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <exception>

class BitcoinExchange{
private:
	std::map<int, double>	_data;
	int 					_firstYear;
	int 					_firstMonth;
	int 					_firstDay;
	int 					_calendar[12];
public:
	BitcoinExchange();

	void	readData();
	void	checkInput(char *file);
	int 	countDays(std::string	date);
	bool	ifValidDate(const std::string& date);
	bool	ifValidValue(const std::string& value);
	int 	getValueFromBase(int);


};


#endif //EX00_BITCOINEXCHANGE_HPP
