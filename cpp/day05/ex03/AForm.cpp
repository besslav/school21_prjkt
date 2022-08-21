//
// Created by Yeast Maragret on 8/2/22.
//

#include "AForm.h"

AForm::AForm() : _name("Default form"), _isSigned(false), _gradeSign(1), _gradeExecute(1) {
    std::cout << "Default constructor AForm" << std::endl;
}

AForm::AForm(std::string name, int grade) : _name(name), _isSigned(false), _gradeSign(grade),
    _gradeExecute(grade) {
    if (grade < 1)
        throw AForm::GradeTooHighException();
    else if (grade > 150)
        throw AForm::GradeTooLowException();
    else {
        std::cout << "Constructor AForm: " + name << std::endl;
    }
}

AForm::AForm(std::string name, int gradeSign, int gradeExecute) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
    if (gradeSign < 1 || gradeExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeSign > 150 || gradeExecute > 150)
        throw AForm::GradeTooLowException();
    else {
        std::cout << "Constructor AForm: " + name << std::endl;
    }
}

AForm::AForm(const AForm &copy) : _name(copy.getName()), _isSigned(copy.getIsSign()), _gradeSign(copy.getGradeSign()), _gradeExecute(copy.getGradeExecute()) {
    std::cout << "Copy constructor AForm: " + _name << std::endl;
}

AForm &AForm::operator=(const AForm &copy) {
    std::cout << "Copy operator AForm: " + _name << std::endl;
    this->_isSigned = copy.getIsSign();
    return *this;
}

AForm::~AForm() {
    std::cout << "Destructor AForm: " + _name << std::endl;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= this->_gradeSign)
        this->_isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

void AForm::beExecute(Bureaucrat &bureaucrat) {
    if (!_isSigned)
        throw AForm::UnsignedFormException();
    else if (bureaucrat.getGrade() > _gradeExecute)
        throw AForm::GradeTooLowException();
}

std::string AForm::getName() const {
    return this->_name;
}

int AForm::getGradeSign() const {
    return this->_gradeSign;
}

int AForm::getGradeExecute() const {
    return this->_gradeExecute;
}

bool AForm::getIsSign() const {
    return this->_isSigned;
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Exceptions: grade > 150";
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Exceptions: grade < 1";
}

const char *AForm::UnsignedFormException::what() const throw() {
    return "Exceptions: the form is not signed";
}

std::ostream & operator << (std::ostream &out, const AForm &form) {
    out << form.getName() + ", AForm grade sign " << form.getGradeSign() << ", grade execute ";
    out << form.getGradeExecute() << ", is sign " << form.getIsSign() << std::endl;
    return out;
}