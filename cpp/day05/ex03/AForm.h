//
// Created by Yeast Maragret on 8/2/22.
//

#ifndef PISCINE_CPP_AFORM_H
#define PISCINE_CPP_AFORM_H

#include <iostream>
#include "Bureaucrat.h"

class Bureaucrat;

class AForm {
public:
    AForm();
    AForm(std::string name, int grade);
    AForm(std::string name, int gradeSign, int gradeExecute);
    AForm(const AForm&);
    AForm& operator=(const AForm&);
    virtual ~AForm();

    std::string getName(void) const;
    bool getIsSign(void) const;
    int getGradeSign(void) const;
    int getGradeExecute(void) const;

    void beSigned(Bureaucrat&);
    virtual void beExecute(Bureaucrat&) = 0;

    class GradeTooHighException : public std::exception {
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw();
    };
    class UnsignedFormException : public std::exception {
        virtual const char* what() const throw();
    };

private:
    const std::string _name;
    bool _isSigned;
    const int _gradeSign;
    const int _gradeExecute;
};

std::ostream & operator << (std::ostream &out, const AForm &AForm);

#endif //PISCINE_CPP_AFORM_H
