//
// Created by Price Skip on 8/17/22.
//

#include "AAnimal.h"

AAnimal::AAnimal() : _type("non"){
	std::cout << "Constructor AAnimal" << std::endl;
}
AAnimal::AAnimal(const std::string &type) : _type(type) {
	std::cout << "Constructor AAnimal name " << _type << std::endl;
}
AAnimal::AAnimal(const AAnimal &copy) : _type(copy._type) {
	std::cout << "Copy constructor AAnimal" << std::endl;
}
AAnimal &AAnimal::operator=(const AAnimal &element) {
	this->_type = element._type;
	std::cout << "Copy operator AAnimal" << std::endl;
	return *this;
}
AAnimal::~AAnimal() {
	std::cout << "Destructor AAnimal" << std::endl;
}
const std::string &AAnimal::getType() const {
	return _type;
}
