//
// Created by Price Skip on 8/17/22.
//

#include "Cat.h"

Cat::Cat() : Animal("Cat") {
	std::cout << "Constructor Cat" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	std::cout << "Copy constructor Cat" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {
	std::cout << "Copy operator Cat" << std::endl;
	this->_type = copy._type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Destructor Cat" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "I'm hungry " << std::endl;
}
