//
// Created by Price Skip on 8/17/22.
//

#include "Brain.h"

Brain::Brain() {
	std::cout << "Constructor Brain" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "";
}

Brain::Brain(const Brain &copy) {
	std::cout << "Copy constructor Brain" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
}

Brain &Brain::operator=(const Brain &copy) {
	std::cout << "Copy operator Brain" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain Destructor" << std::endl;
}
