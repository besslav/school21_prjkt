#include <iostream>

#include "Array.hpp"

int main() {
    Array<int> arr;
    std::cout << "arr size = " << arr.size() << std::endl;
    try {
        std::cout << arr[0] << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    Array<int> arr1(10);
    std::cout << "arr1 size = " << arr1.size() << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << "arr1[" << i << "] = " << arr1[i] << std::endl;
    }
    std::cout << std::endl;
    try {
        std::cout << arr1[10] << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << arr1[-1] << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; ++i) {
        arr1[i] = i;
    }
    for (int i = 0; i < 10; ++i) {
        std::cout << "arr1[" << i << "] = " << arr1[i] << std::endl;
    }
    std::cout << std::endl;
}
