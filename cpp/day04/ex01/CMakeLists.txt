cmake_minimum_required(VERSION 3.21)
project(ex01)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex01 main.cpp main.cpp Animal.cpp Animal.h Dog.cpp Dog.h Cat.cpp Cat.h Brain.cpp Brain.h)
