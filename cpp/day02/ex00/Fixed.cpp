//
// Created by Price Skip on 8/12/22.
//

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constract" << std::endl;
	this->_raw = 0;
}

Fixed::~Fixed()
{
	std::cout << "destract" << std::endl;
}

Fixed::Fixed(const Fixed &pre_fixed) : _raw(pre_fixed.getRawBits())
{
	std::cout << "constract with copy" << std::endl;

}

Fixed &Fixed::operator=(const Fixed &pre_fixed)
{
	std::cout << "Copy assignment operator Fixed" << std::endl;
	_raw = pre_fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function" << std::endl;
	return this->_raw;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function" << std::endl;
	this->_raw = raw;
}