//
// Created by Price Skip on 8/12/22.
//
#include "Point.hpp"

int main( void ) {
		Point a, b(7, 0), c(15, 0), point(50, 50);
		if (bsp(a, b, c, point))
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
		return 0;

}