
#ifndef PISCINE_CPP_ROBOTOMYREQUESTFORM_H
#define PISCINE_CPP_ROBOTOMYREQUESTFORM_H

#include "AForm.h"
#include <stdlib.h>

class RobotomyRequestForm  : public AForm {
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(const RobotomyRequestForm&);
    RobotomyRequestForm& operator=(const RobotomyRequestForm&);
    ~RobotomyRequestForm();

    std::string getTarget(void) const;

    void beExecute(Bureaucrat&);

private:
    std::string _target;
};


#endif //PISCINE_CPP_ROBOTOMYREQUESTFORM_H
