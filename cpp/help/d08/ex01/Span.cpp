/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:33:20 by drayl             #+#    #+#             */
/*   Updated: 2022/03/28 22:33:21 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &element) { *this = element; }

Span &Span::operator=(const Span &element) {
    this->_n = element._n;
    this->_array = element._array;
    return (*this);
}

void Span::addNumber(int newNum) {
    if (this->_array.size() < this->_n)
        this->_array.push_back(newNum);
    else
        throw std::out_of_range("Array is full!");
}

void Span::addNumber(std::vector<int>::iterator it1, std::vector<int>::iterator it2) {
    if (it2 <= it1)
        throw std::logic_error("Incorrect iterator order");
    if (this->_array.size() + (it2 - it1) > this->_n)
        throw std::out_of_range("It is impossible to fit so many elements into an array");
    this->_array.insert(this->_array.end(), it1, it2);
}

int Span::longestSpan() {
    if (this->_array.size() < 2)
        throw std::logic_error("To find the difference between the elements there must be at least 2");
    return (*(std::max_element(this->_array.begin(), this->_array.end()))
    - *(std::min_element(this->_array.begin(), this->_array.end())));
}

int Span::shortestSpan() {
    int result = longestSpan();
    std::vector<int>::iterator it1 = this->_array.begin();
    std::vector<int>::iterator it2 = it1 + 1;
    std::vector<int>::iterator end = this->_array.end();
    while (it1 != (end - 1)) {
        while (++it2 != end) {
            if (abs(*it1 - *it2) < result)
                result = abs(*it1 - *it2);
        }
        it2 = ++it1;
    }
    return (result);
}
