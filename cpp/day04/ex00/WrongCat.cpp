//
// Created by Price Skip on 8/17/22.
//

#include "WrongCat.h"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "Constructor WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	std::cout << "Copy constructor WrongCat" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
	std::cout << "Copy operator WrongCat" << std::endl;
	this->_type = copy._type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "Destructor WrongCat" << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "I'm hungry " << std::endl;
}
