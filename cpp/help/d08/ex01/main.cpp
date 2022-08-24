/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:33:10 by drayl             #+#    #+#             */
/*   Updated: 2022/03/28 22:33:12 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {

    std::cout << std::endl << "BLOCK 1" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << std::endl << "BLOCK 2" << std::endl;
    Span span1 = Span(1);
    try {
        span1.addNumber(10);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        span1.addNumber(1);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        span1.longestSpan();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        span1.shortestSpan();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "BLOCK 3" << std::endl;
    Span span2 = Span(10);
    try {
        for (int i = 0; i < 11; ++i) {
            span2.addNumber(i);
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Shortest Span " << span2.shortestSpan() << std::endl;
    std::cout << "Longest Span " << span2.longestSpan() << std::endl;

    std::cout << std::endl << "BLOCK 4" << std::endl;
    Span span3 = Span(100);
    std::vector<int> arr1;
    for (int i = 0; i <= 150; i += 2) {
        arr1.push_back(i);
    }
    try {
        span3.addNumber(arr1.end(), arr1.begin());
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    span3.addNumber(arr1.begin(), arr1.end());
    try {
        span3.addNumber(arr1.begin(), arr1.end());
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "BLOCK 5" << std::endl;
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
