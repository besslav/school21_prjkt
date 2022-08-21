//
// Created by Yeast Maragret on 8/3/22.
//

#include "Intern.h"

Intern::Intern() {
    std::cout << "Constructor Intern" << std::endl;
}

Intern::Intern(const Intern &copy) {
    (void) copy;
    std::cout << "Copy constructor Intern" << std::endl;
}

Intern &Intern::operator=(const Intern &) {
    std::cout << "Copy operator Intern" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Destructor Intern" << std::endl;
}

AForm *Intern::moveForm(std::string name, std::string target) {
    AForm *newForm = NULL;
    std::string	names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int index = -1;
    for (int i = 0; i < 3; ++i)
        if (name == names[i])
            index = i;
    switch (index) {
        case 0:
            newForm = new ShrubberyCreationForm(target);
            std::cout << "Intern creates " + names[index] << std::endl;
            break;
        case 1:
            newForm = new RobotomyRequestForm(target);
            std::cout << "Intern creates " + names[index] << std::endl;
            break;
        case 2:
            newForm = new PresidentialPardonForm(target);
            std::cout << "Intern creates " + names[index] << std::endl;
            break;
        default:
            std::cout << "Invalid form name" << std::endl;
    }
    return newForm;
}