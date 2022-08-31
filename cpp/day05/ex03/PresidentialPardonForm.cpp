#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5),
    _target("default target") {
    std::cout << "Default constructor PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
    AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "Constructor PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy),
    _target(copy.getTarget()) {
    std::cout << "Copy constructor PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
    std::cout << "Copy operator PresidentialPardonForm" << std::endl;
    _target = copy.getTarget();
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Destructor PresidentialPardonForm" << std::endl;
}

void PresidentialPardonForm::beExecute(Bureaucrat &bureaucrat) {
    AForm::beExecute(bureaucrat);
    std::cout << "The " + _target + " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
    return this->_target;
}