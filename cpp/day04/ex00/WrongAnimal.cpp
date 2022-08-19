//
// Created by Price Skip on 8/17/22.
//

#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : _type("nono"){
	std::cout << "Constructor WrongAnimal" << std::endl;
}
WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {
	std::cout << "Constructor WrongAnimal name " << _type << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &copy) : _type(copy._type) {
	std::cout << "Copy constructor WrongAnimal" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &) {
	std::cout << "Copy operator WrongAnimal" << std::endl;
	return *this;
}
WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor WrongAnimal" << std::endl;
}
const std::string &WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal sound" << std::endl;
}