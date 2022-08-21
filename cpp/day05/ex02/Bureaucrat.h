

#ifndef PISCINE_CPP_BUREAUCRAT_H
#define PISCINE_CPP_BUREAUCRAT_H

#include <string>
#include <iostream>
#include "AForm.h"

class AForm;

class Bureaucrat {
public:
    Bureaucrat();
    Bureaucrat(std::string, int);
    Bureaucrat(Bureaucrat const &);
    Bureaucrat& operator=(Bureaucrat const &);
    ~Bureaucrat();

    std::string getName(void) const;
    int getGrade(void) const;

    void incGrade(void);
    void decGrade(void);
    void signForm(AForm &);
    void executeForm(AForm &);

    class GradeTooHighException : public std::exception {
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw();
    };

private:
    std::string const _name;
    int _grade;
};

std::ostream & operator << (std::ostream &out, const Bureaucrat &bureaucrat);

#endif //PISCINE_CPP_BUREAUCRAT_H
