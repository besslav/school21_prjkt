//
// Created by Price Skip on 8/17/22.
//

#include "Cat.h"

Cat::Cat(){
	this->_brain = new Brain();
	this->_type = "Cat";
	std::cout << "Constructor Cat" << std::endl;
}

Cat::Cat(const Cat &copy): AAnimal(copy) {
	std::cout << "Copy constructor Cat" << std::endl;
	this->_brain = new Brain(*copy._brain);
}

Cat &Cat::operator=(const Cat &copy) {
	std::cout << "Copy operator Cat" << std::endl;
	if (this == &copy)
		return  *this;
	delete (this->_brain);
	this->_type = copy._type;
	this->_brain = new Brain(copy.getBrain());
	return *this;
}

Cat::~Cat() {
	std::cout << "Destructor Cat" << std::endl;
	delete(this->_brain);
}

void Cat::makeSound() const{
	std::cout << "I'm hungry " << std::endl;
}

Brain Cat::getBrain() const {
	return *(this->_brain);
}
