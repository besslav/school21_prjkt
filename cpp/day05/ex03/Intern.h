#ifndef PISCINE_CPP_INTERN_H
#define PISCINE_CPP_INTERN_H

#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

class Intern {
public:
    Intern();
    Intern(const Intern&);
    Intern& operator=(const Intern&);
    ~Intern();

    AForm *moveForm(std::string name, std::string target);
};


#endif //PISCINE_CPP_INTERN_H
