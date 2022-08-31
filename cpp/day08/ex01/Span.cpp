//
// Created by Price Skip on 8/27/22.
//

#include "Span.h"

Span::Span(const unsigned int size) {
	_size = size;
}

Span &Span::operator=(const Span &copy) {
	_size = copy._size;
	_array = copy._array;
	return (*this);
}

Span::Span(const Span &copy) {
	*this = copy;
}

void Span::addNumber(const int &num)
{
	if (_array.size() < _size)
		_array.push_back(num);
	else
		throw std::out_of_range("Array is full!");
}

void Span::addNumber(std::vector<int>::iterator it1, std::vector<int>::iterator it2) {
	if (it2 <= it1)
		throw std::logic_error("Incorrect iterator order");
	if (this->_array.size() + (it2 - it1) > this->_size)
		throw std::out_of_range("It is impossible to fit so many elements into an array");
	this->_array.insert(this->_array.end(), it1, it2);
}

int Span::longestSpan() {
	if (_array.size() > 1) {
		return (*std::max_element(_array.begin(), _array.end())
		- *std::min_element(_array.begin(), _array.end()));
	}
	else
		throw std::logic_error("To find the difference between the elements there must be at least 2");
}

int Span::shortestSpan()
{
	std::vector<int>::iterator it1 = this->_array.begin();
	std::vector<int>::iterator it2 = it1 + 1;
	std::vector<int>::iterator end = this->_array.end();
	int res = abs(*it1 - *it2);
	it2++;
	while(it1 != end - 1)
	{
		while(it2 != end)
		{
			if (abs(*it1 - *it2) < res)
				res = abs(*it1 - *it2);
			it2++;
		}
		it1++;
		it2 = it1 + 1;
	}
	return (res);
}
