//
// Created by Price Skip on 8/17/22.
//

#include "Animal.h"

Animal::Animal() : _type("nono"){
	std::cout << "Constructor Animal" << std::endl;
}
Animal::Animal(const std::string &type) : _type(type) {
	std::cout << "Constructor Animal name " << _type << std::endl;
}
Animal::Animal(const Animal &copy) : _type(copy._type) {
	std::cout << "Copy constructor Animal" << std::endl;
}
Animal &Animal::operator=(const Animal &) {
	std::cout << "Copy operator Animal" << std::endl;
	return *this;
}
Animal::~Animal() {
	std::cout << "Destructor Animal" << std::endl;
}
const std::string &Animal::getType() const {
	return _type;
}

void Animal::makeSound() const{
	std::cout << "Animal sound" << std::endl;
}