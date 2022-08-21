//
// Created by Price Skip on 8/19/22.
//

#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : _name("Default_Name"), _grade(150) {
	std::cout << "Default constructor Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else {
		this->_grade = grade;
		std::cout << "Constructor Bureaucrat: " + name + ", grade: " << grade << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {
	std::cout << "Copy constructor Bureaucrat: " + _name << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	std::cout << "Copy operator Bureaucrat: " + _name << std::endl;
	this->_name = copy._name;
	this->_grade = copy.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor Bureaucrat: " + _name << std::endl;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::decGrade() {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::incGrade() {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Exceptions: grade > 150";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Exceptions: grade < 1";
}

std::ostream & operator << (std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() + ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return out;
}
