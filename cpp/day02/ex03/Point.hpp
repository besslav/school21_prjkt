//
// Created by Price Skip on 8/15/22.
//
#include "Fixed.hpp"

#ifndef POINT_HPP
#define POINT_HPP


class Point {
private:
	Fixed _x;
	Fixed _y;
public:
	Point();
	Point(const Fixed&, const Fixed&);
	Point(const Point&);
	Point& operator=(const Point&);
	~Point();
	Fixed getX(void) const;
	void setX(const Fixed value);
	Fixed getY(void) const;
	void setY(const Fixed value);

};

bool bsp(Point A, Point B, Point C, Point O);
#endif //POINT_HPP
