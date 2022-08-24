/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:33:25 by drayl             #+#    #+#             */
/*   Updated: 2022/03/28 22:33:26 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span {
private:
    unsigned int _n;
    std::vector<int> _array;
    Span() {}
public:
    Span(unsigned int n);
    Span(const Span &element);
    Span &operator=(const Span &element);
    ~Span() {}

    void addNumber(int newNum);
    void addNumber(std::vector<int>::iterator it1, std::vector<int>::iterator it2);
    int shortestSpan();
    int longestSpan();
};

#endif
