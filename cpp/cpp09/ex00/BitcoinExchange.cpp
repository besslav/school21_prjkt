//
// Created by Price Skip on 4/11/23.
//
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	for (int i=0; i < 12; i++){
		_calendar[i] = days[i];
	}
	_firstYear = 2009;
	_firstMonth = 1;
	_firstDay = 1;
}

int BitcoinExchange::countDays(std::string	date) {
	int year = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(5, 2));
	int day = std::stoi(date.substr(8, 2));
	int daysDiff = 0;

	daysDiff += day - _firstDay;
	while (month > _firstMonth){
		daysDiff += _calendar[month-2];
		if (month == 3) {
			if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
				daysDiff += 1;
		}
		month--;
	}
	while (year > _firstYear){
		if (((year-1 % 4 == 0) && (year-1 % 100 != 0)) || (year-1 % 400 == 0))
			daysDiff += 366;
		else
			daysDiff += 365;
		year--;
	}
	return daysDiff;
}

void BitcoinExchange::readData() {
	std::ifstream file("data.csv");
	std::string line;

	getline(file, line);
	while(std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date, rate;
		std::getline(ss, date, ',');
		std::getline(ss, rate, ',');

		int day = countDays(date);
		double cost = std::stod(rate);
		_data.insert(std::pair<int,double>(day,cost));
	}
}

bool BitcoinExchange::ifValidDate(const std::string& date) {
	if (date.length() != 10)
		return false;
	int year, month, day;
	char sep1, sep2;
	std::istringstream ss(date);
	ss >> year >> sep1 >> month >> sep2 >> day;
	if (ss.fail() || sep1 != '-' || sep2 != '-' || year < 0
		|| month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	bool leap_year = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	if ((month == 2 && (leap_year ? day < 29 : day > 28))
		|| ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
		return false;
	return true;
}
bool BitcoinExchange::ifValidValue(const std::string& value) {
	try {
		std::stof(value);
	}
	catch (const std::invalid_argument& e) {
		return false;
	}
	return true;
}

int BitcoinExchange::getValueFromBase(int day) {
	while (true){
		if (_data.find(day) != _data.end()){
			return day;
		} else
			day--;
	}
}

void BitcoinExchange::checkInput(char *file) {
	std::ifstream inputFile(file);
	if (!inputFile) {
		std::cerr << "Error: Failed to open file." << std::endl;
		exit(1);
	}
	std::string firstLine;
	std::getline(inputFile, firstLine);
	if(firstLine.compare("date | value")) {
		std::cerr << "Error: First line of file is not \"date | value\"." << std::endl;
		exit(1);
	}
	std::string line;
	while (std::getline(inputFile, line)) {
		std::stringstream iss(line);
		std::string date;
		std::string value;
		char separator;

		if (!(iss >> date >> separator >> value) || separator != '|')
			std::cout << "Error: bad input => " << date << std::endl;
		else if (!ifValidDate(date) || !ifValidValue(value))
			std::cout << "Error: bad input => " << date << std::endl;
		else{
			double numOfBits = stod(value);
			int day = countDays(date);
			if (day < 1){
				std::cout << "Error: bad input => " << date << std::endl;
			}
			else if (numOfBits < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (numOfBits > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else {
				int valueInDict = getValueFromBase(day);
				std::cout << date << "=>" << numOfBits << "=" << numOfBits * _data.at(valueInDict) << std::endl;
			}
		}
	}
	inputFile.close();
}
