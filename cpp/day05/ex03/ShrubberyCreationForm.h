//
// Created by Yeast Maragret on 8/3/22.
//

#ifndef PISCINE_CPP_SHRUBBERYCREATIONFORM_H
#define PISCINE_CPP_SHRUBBERYCREATIONFORM_H

#include "AForm.h"
#include <fstream>

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &);
    ~ShrubberyCreationForm();

    std::string getTarget(void) const;

    void beExecute(Bureaucrat&);

    class CreatedFileException : public std::exception {
        virtual const char* what() const throw();
    };

private:
    std::string _target;
};


#endif //PISCINE_CPP_SHRUBBERYCREATIONFORM_H
