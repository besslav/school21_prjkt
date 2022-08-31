#include <iostream>

#include "Span.h"

int main() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "---------------------------------" << std::endl;
	Span span4 = Span(10001);
	std::vector<int> arr2;
	arr2.reserve(10000);
	for (int i = 0; i < 10000; ++i) {
		arr2.push_back(i);
	}
	try {
		span4.addNumber(arr2.begin(), arr2.end());
		std::cout << "Shortest Span " << span4.shortestSpan() << std::endl;
		std::cout << "Longest Span " << span4.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
