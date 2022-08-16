//
// Created by Price Skip on 8/12/22.
//

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "harl was constructed" << std::endl;
}

Harl::~Harl()
{
	std::cout << "harl was destructed" << std::endl;
}

void Harl::debug()
{
	std::cout << "DEBUG" << std::endl;
	std::cout << "I love having extra bacon for my "
				 "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "INFO" << std::endl;
	std::cout <<  "I cannot believe adding extra bacon costs more money. You didn’t put "
				  "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "WARNING" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for "
				 "years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "ERROR" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string funcName[4] = {"debug", "info", "warning", "error"};
	int startLevel = -1;
	for (int i = 0; i < 4; i++)
		if (funcName[i] == level)
			startLevel = i;
	switch (startLevel) {
		case 0:
			(this->*(func[startLevel++]))();
		case 1:
			(this->*(func[startLevel++]))();
		case 2:
			(this->*(func[startLevel++]))();
		case 3:
			(this->*(func[startLevel]))();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

