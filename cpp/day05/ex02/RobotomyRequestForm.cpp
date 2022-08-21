
#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45),
                                                   _target("default target") {
    std::cout << "Default constructor RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
        AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "Constructor RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy),
                                                                                     _target(copy.getTarget()) {
    std::cout << "Copy constructor RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
    std::cout << "Copy operator RobotomyRequestForm" << std::endl;
    _target = copy.getTarget();
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Destructor RobotomyRequestForm" << std::endl;
}

void RobotomyRequestForm::beExecute(Bureaucrat &bureaucrat) {
    AForm::beExecute(bureaucrat);
    srand(time(NULL));
    int isSuccess = rand() % 2;
    std::cout << "Bzzzzz..." << std::endl;
    std::cout << "Drr-drrr-drr..." << std::endl;
    std::cout << "Bzzzzzzzzzzzzz..." << std::endl;
    if (isSuccess)
        std::cout << "The " + _target + " was successfully robotomized" << std::endl;
    else
        std::cout << "The robotomy is failed" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
    return this->_target;
}