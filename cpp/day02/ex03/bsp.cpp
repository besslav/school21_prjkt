//
// Created by Price Skip on 8/15/22.
//

#include "Point.hpp"

bool bsp(Point A, Point B, Point C, Point O)
{
	Fixed OABVector = (A.getX() - O.getX()) * (B.getY() - A.getY()) - ((B.getX() - A.getX()) * (A.getY() - O.getY()));
	Fixed OBCVector = (B.getX() - O.getX()) * (C.getY() - B.getY()) - ((C.getX() - B.getX()) * (B.getY() - O.getY()));
	Fixed OCAVector = (C.getX() - O.getX()) * (A.getY() - C.getY()) - ((A.getX() - C.getX()) * (C.getY() - O.getY()));

	if ((OABVector > 0 && OBCVector > 0 && OCAVector > 0) || (OABVector < 0 && OBCVector < 0 && OCAVector < 0)){
		return true;
	}
	return false;
}