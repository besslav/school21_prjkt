cmake_minimum_required(VERSION 3.21)
project(ex03)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex03 main.cpp Bureaucrat.h	AForm.h		PresidentialPardonForm.h	RobotomyRequestForm.h
        ShrubberyCreationForm.h		Intern.h Bureaucrat.cpp				AForm.cpp
        PresidentialPardonForm.cpp	RobotomyRequestForm.cpp		ShrubberyCreationForm.cpp
        Intern.cpp)
