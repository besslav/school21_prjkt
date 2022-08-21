//
// Created by Yeast Maragret on 8/1/22.
//

#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "Intern.h"

int main(void) {
    Bureaucrat bureaucrat("Mick", 2);
    Bureaucrat bureaucrat1("Nelly", 13);
    Bureaucrat bureaucrat2("Dory", 61);
    Bureaucrat bureaucrat3("Tisha", 140);
    Bureaucrat bureaucrat4("Lari", 148);
    Intern intern;
    AForm *form = NULL;

    std::cout << "***************" << std::endl;
    try {
        form = intern.moveForm("presidential pardon", "Angy");
        bureaucrat.executeForm(*form);
        bureaucrat2.signForm(*form);
        bureaucrat1.signForm(*form);
        bureaucrat1.executeForm(*form);
        bureaucrat.executeForm(*form);
        std::cout << "***************" << std::endl;
        delete(form);
    } catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    std::cout << "***************" << std::endl;
    try {
        form = intern.moveForm("robotomy request", bureaucrat4.getName());
        bureaucrat.executeForm(*form);
        bureaucrat3.signForm(*form);
        bureaucrat2.signForm(*form);
        bureaucrat2.executeForm(*form);
        bureaucrat1.executeForm(*form);
        std::cout << "***************" << std::endl;
        delete(form);
    } catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    std::cout << "***************" << std::endl;
    try {
        form = intern.moveForm("shrubbery creation", "garden");
        bureaucrat.executeForm(*form);
        bureaucrat4.signForm(*form);
        bureaucrat3.signForm(*form);
        bureaucrat3.executeForm(*form);
        bureaucrat2.executeForm(*form);
        std::cout << "***************" << std::endl;
        delete(form);
    } catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    std::cout << "***************" << std::endl;
    form = intern.moveForm("shrub creation", "garden");
    if (form)
        delete(form);
    std::cout << "***************" << std::endl;
}