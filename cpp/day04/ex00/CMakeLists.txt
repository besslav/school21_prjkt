cmake_minimum_required(VERSION 3.21)
project(ex00)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex00 main.cpp Animal.cpp Animal.h Dog.cpp Dog.h Cat.cpp Cat.h WrongAnimal.cpp WrongAnimal.h WrongCat.cpp WrongCat.h)
