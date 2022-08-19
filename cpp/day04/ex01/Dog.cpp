//
// Created by Price Skip on 8/17/22.
//

#include "Dog.h"

Dog::Dog() : Animal("Dog") {
	this->_brain = new Brain();
	std::cout << "Constructor Dog" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	std::cout << "Copy constructor Dog" << std::endl;
	this->_brain = new Brain(copy.getBrain());
}

Dog &Dog::operator=(const Dog &copy) {
	std::cout << "Copy operator Dog" << std::endl;
	this->_type = copy.getType();
	this->_brain = new Brain(copy.getBrain());
	return *this;
}

Dog::~Dog() {
	std::cout << "Destructor Dog" << std::endl;
	delete(this->_brain);
}

void Dog::makeSound() const{
	std::cout << "Auf" << std::endl;
}
Brain Dog::getBrain() const {
	return *(this->_brain);
}