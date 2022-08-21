//
// Created by Yeast Maragret on 8/3/22.
//

#ifndef PISCINE_CPP_PRESIDENTIALPARDONFORM_H
#define PISCINE_CPP_PRESIDENTIALPARDONFORM_H

#include "AForm.h"
class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string target);
    PresidentialPardonForm(const PresidentialPardonForm&);
    PresidentialPardonForm& operator=(const PresidentialPardonForm&);
    ~PresidentialPardonForm();

    std::string getTarget(void) const;

    void beExecute(Bureaucrat&);

private:
    std::string _target;
};

#endif //PISCINE_CPP_PRESIDENTIALPARDONFORM_H
