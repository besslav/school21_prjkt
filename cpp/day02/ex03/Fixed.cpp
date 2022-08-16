//
// Created by Price Skip on 8/12/22.
//

#include "Fixed.hpp"

Fixed::Fixed() : _value(0){}
Fixed::Fixed(const int value) : _value(value << _frac){}
Fixed::Fixed(const float value) : _value(roundf(value * (1 << _frac))){}
Fixed::Fixed(const Fixed &copy) : _value(copy.getRawBits()){}

Fixed& Fixed::operator=(const Fixed &copy){
	if (this == &copy)
		return *this;
	this->_value = copy.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &compar) const{
	if (_value > compar._value)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &compar) const{
	if (_value < compar._value)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &compar) const{
	if (_value >= compar._value)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &compar) const{
	if (_value <= compar._value)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &compar) const{
	if (_value != compar._value)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &compar) const{
	if (_value == compar._value)
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed &compar) const{
	float itog = this->toFloat() + compar.toFloat();
	return (itog);
}

Fixed Fixed::operator-(const Fixed &compar) const{
	float itog = this->toFloat() - compar.toFloat();
	return (itog);
}

Fixed Fixed::operator*(const Fixed &compar) const{
	float itog = this->toFloat() * compar.toFloat();
	return (itog);
}

Fixed Fixed::operator/(const Fixed &compar) const{
	float itog = this->toFloat() / compar.toFloat();
	return (itog);
}


Fixed Fixed::operator++() {
	this->_value += 1;
	return *this;
}

Fixed Fixed::operator--() {
	this->_value-= 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed oldValue(*this);
	this->_value += 1;
	return oldValue;
}

Fixed Fixed::operator--(int) {
	Fixed oldValue(*this);
	this->_value -= 1;
	return oldValue;
}


Fixed &Fixed::min(Fixed &one, Fixed &two) {
	if (one <= two)
		return one;
	return two;
}

Fixed &Fixed::max(Fixed &one, Fixed &two) {
	if (one >= two)
		return one;
	return two;
}

const Fixed &Fixed::min(Fixed const &one, Fixed const &two) {
	if (one <= two)
		return one;
	return two;
}

const Fixed &Fixed::max(Fixed const &one, Fixed const &two) {
	if (one >= two)
		return one;
	return two;
}

Fixed::~Fixed(){}


std::ostream & operator << (std::ostream &out, const Fixed &fixed){
	out << fixed.toFloat();
	return out;
}

float Fixed::toFloat() const{
	return ((float)this->_value / (1 << _frac));
}

int Fixed::toInt() const{
	return (this->_value >> _frac);
}

int Fixed::getRawBits(void) const{
	return this->_value;
}

void Fixed::setRawBits(const int raw){
	this->_value = raw;
}