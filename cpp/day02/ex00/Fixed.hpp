//
// Created by Price Skip on 8/12/22.
//

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	_raw;
	static const int frac = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed&);
	Fixed& operator=(const Fixed&);

	int getRawBits(void) const;
	void setRawBits(int const raw);

};


#endif //FIXED_HPP
