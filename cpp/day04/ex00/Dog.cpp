//
// Created by Price Skip on 8/17/22.
//

#include "Dog.h"

Dog::Dog() : Animal("Dog") {
	std::cout << "Constructor Dog" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	std::cout << "Copy constructor Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {
	std::cout << "Copy operator Dog" << std::endl;
	this->_type = copy._type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Destructor Dog" << std::endl;
}

void Dog::makeSound() const{
	std::cout << "Auf" << std::endl;
}