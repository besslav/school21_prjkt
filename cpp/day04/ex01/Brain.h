//
// Created by Price Skip on 8/17/22.
//

#ifndef EX01_BRAIN_H
#define EX01_BRAIN_H

#include <iostream>

class Brain {
public:
	Brain();
	Brain(const Brain &copy);
	Brain& operator=(const Brain &copy);
	~Brain();

protected:
	std::string _ideas[100];
};


#endif //EX01_BRAIN_H
