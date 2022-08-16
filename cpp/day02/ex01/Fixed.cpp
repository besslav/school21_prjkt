//
// Created by Price Skip on 8/12/22.
//

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor Fixed" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : _value(copy.getRawBits()) {
	std::cout << "Copy constructor Fixed" << std::endl;
}

Fixed::Fixed(const int row) : _value(row << _frac)
{
	std::cout << "Integer constructor Fixed" << std::endl;
}

Fixed::Fixed(const float row) : _value(roundf(row * (1 << _frac)))
{
	std::cout << "Float constructor Fixed" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator Fixed" << std::endl;
	if (this == &copy)
		return *this;
	this->_value = copy.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor Fixed" << std::endl;
}


std::ostream & operator << (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

float Fixed::toFloat() const
{
	return ((float)this->_value / (1 << _frac));
}

int Fixed::toInt() const
{
	return (this->_value >> _frac);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function" << std::endl;
	this->_value = raw;
}