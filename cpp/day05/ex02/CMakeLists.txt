cmake_minimum_required(VERSION 3.21)
project(ex02)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex02  main.cpp Bureaucrat.cpp Bureaucrat.h AForm.cpp AForm.h
        PresidentialPardonForm.cpp PresidentialPardonForm.h
        RobotomyRequestForm.cpp RobotomyRequestForm.h
        ShrubberyCreationForm.cpp ShrubberyCreationForm.h)
