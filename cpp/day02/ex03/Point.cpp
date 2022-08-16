//
// Created by Price Skip on 8/15/22.
//

#include "Point.hpp"

Point::Point() : _x(0), _y(0){}
Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y){}
Point::Point(const Point &copy) : _x(copy.getX()), _y(copy.getY()){}
Point& Point::operator=(const Point &copy){
	if (this == &copy)
		return *this;
	this->_x = copy.getX();
	this->_y = copy.getY();
	return *this;
}
Point::~Point(){}
Fixed Point::getX(void) const{
	return this->_x;
}
void Point::setX(const Fixed x){
	this->_x = x;
}
Fixed Point::getY(void) const{
	return this->_y;
}
void Point::setY(const Fixed y){
	this->_y = y;
}

