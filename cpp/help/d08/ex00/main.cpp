/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:33:38 by drayl             #+#    #+#             */
/*   Updated: 2022/03/28 22:33:39 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
# include "easyfind.hpp"

int main() {
    std::vector<int> arr;
    std::vector<int>::iterator it;

    for (int i = 0; i < 100; ++i) {
        arr.push_back(i);
    }

    try {
        it = easyfind(arr, 0);
        std::cout << *it << std::endl;
        std::cout << std::endl;

        it = easyfind(arr, -1);
        std::cout << *it << std::endl;
        std::cout << std::endl;
    } catch (...) {
        std::cerr << "Error: Invalid value" << std::endl;
    }

    try {
        it = easyfind(arr, 99);
        std::cout << *it << std::endl;
        std::cout << std::endl;

        it = easyfind(arr, 100);
        std::cout << *it << std::endl;
        std::cout << std::endl;
    } catch (...) {
        std::cerr << "Error: Invalid value" << std::endl;
    }

}
