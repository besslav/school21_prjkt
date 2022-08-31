//
// Created by Price Skip on 8/27/22.
//

#ifndef EX01_SPAN_H
#define EX01_SPAN_H

# include <iostream>
# include <vector>

class Span {
private:
	std::vector<int>	_array;
	unsigned int		_size;
	Span() {}
public:
	Span(unsigned int size);
	~Span() {}
	Span(const Span &copy);
	Span &operator=(const Span &copy);

	void addNumber(const int&);
	void addNumber(std::vector<int>::iterator it1, std::vector<int>::iterator it2);
	int	longestSpan();
	int shortestSpan();




};


#endif //EX01_SPAN_H
