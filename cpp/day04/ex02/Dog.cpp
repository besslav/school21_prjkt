//
// Created by Price Skip on 8/17/22.
//

#include "Dog.h"

Dog::Dog(){
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Constructor Dog" << std::endl;
}

Dog::Dog(const Dog &copy): AAnimal(copy){
	std::cout << "Copy constructor Dog" << std::endl;
	this->_brain = new Brain(*copy._brain);
}

Dog &Dog::operator=(const Dog &copy) {
	std::cout << "Copy operator Dog" << std::endl;
	if (this == &copy)
		return  *this;
	delete (this->_brain);
	this->_type = copy._type;
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
