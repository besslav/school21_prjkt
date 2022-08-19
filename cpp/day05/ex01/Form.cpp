//
// Created by Price Skip on 8/19/22.
//

#include "Form.h"

Form::Form() : _name("Default form"), _isSigned(false), _gradeSign(1), _gradeExecute(1) {
	std::cout << "Default constructor Form" << std::endl;
}

Form::Form(std::string name, int grade) : _name(name), _isSigned(false), _gradeSign(grade),
										  _gradeExecute(grade) {
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	else {
		std::cout << "Constructor Form: " + name << std::endl;
	}
}

Form::Form(std::string name, int gradeSign, int gradeExecute) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
	if (gradeSign < 1 || gradeExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw Form::GradeTooLowException();
	else {
		std::cout << "Constructor Form: " + name << std::endl;
	}
}

Form::Form(const Form &copy) : _name(copy.getName()), _isSigned(copy.getIsSign()), _gradeSign(copy.getGradeSign()), _gradeExecute(copy.getGradeExecute()) {
	std::cout << "Copy constructor Form: " + _name << std::endl;
}

Form &Form::operator=(const Form &copy) {
	std::cout << "Copy operator Form: " + _name << std::endl;
	this->_isSigned = copy.getIsSign();
	return *this;
}

Form::~Form() {
	std::cout << "Destructor Form: " + _name << std::endl;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradeSign)
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::string Form::getName() const {
	return this->_name;
}

int Form::getGradeSign() const {
	return this->_gradeSign;
}

int Form::getGradeExecute() const {
	return this->_gradeExecute;
}

bool Form::getIsSign() const {
	return this->_isSigned;
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Exceptions: grade > 150";
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Exceptions: grade < 1";
}

std::ostream & operator << (std::ostream &out, const Form &form) {
	out << form.getName() + ", Form grade sign " << form.getGradeSign() << ", grade execute ";
	out << form.getGradeExecute() << ", is sign " << form.getIsSign() << std::endl;
	return out;
}