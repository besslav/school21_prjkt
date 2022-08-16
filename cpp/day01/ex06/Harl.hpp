//
// Created by Price Skip on 8/12/22.
//

#ifndef HARL_HPP
#define HARL_HPP


#include <string>
#include <iostream>

class Harl {
public:
	Harl(void);
	~Harl(void);
	void complain(std::string level);

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};


#endif //HARL_HPP
