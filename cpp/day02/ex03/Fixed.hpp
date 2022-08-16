//
// Created by Price Skip on 8/12/22.
//

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
private:
	int	_value;
	static const int _frac = 8;

public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed&);
	Fixed& operator=(const Fixed&);

	bool operator>(const Fixed&) const;
	bool operator<(const Fixed&) const;
	bool operator>=(const Fixed&) const;
	bool operator<=(const Fixed&) const;
	bool operator!=(const Fixed&) const;
	bool operator==(const Fixed&) const;

	Fixed operator+(const Fixed&) const;
	Fixed operator-(const Fixed&) const;
	Fixed operator*(const Fixed&) const;
	Fixed operator/(const Fixed&) const;

	Fixed operator++();      //pre
	Fixed operator--();
	Fixed operator++(int);   //post
	Fixed operator--(int);

	static Fixed &min(Fixed &one, Fixed &two);
	static const Fixed &min(Fixed const &one, Fixed const &two);
	static Fixed &max(Fixed &one, Fixed &two);
	static const Fixed &max(Fixed const &one, Fixed const &two);

	~Fixed();

	friend std::ostream & operator << (std::ostream &out, const Fixed &fixed);
	float toFloat( void ) const;
	int toInt( void ) const;

	int getRawBits(void) const;
	void setRawBits(int const value);

};

std::ostream & operator << (std::ostream &out, const Fixed &fixed);
#endif //FIXED_HPP
