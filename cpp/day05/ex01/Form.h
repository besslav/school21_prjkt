//
// Created by Price Skip on 8/19/22.
//

#ifndef EX01_FORM_H
#define EX01_FORM_H

#include <iostream>
#include "Bureaucrat.h"

class Bureaucrat;

class Form {
public:
	Form();
	Form(std::string name, int grade);
	Form(std::string name, int gradeSign, int gradeExecute);
	Form(const Form&);
	Form& operator=(const Form&);
	~Form();

	void beSigned(Bureaucrat &bureaucrat);

	std::string getName(void) const;
	bool getIsSign(void) const;
	int getGradeSign(void) const;
	int getGradeExecute(void) const;

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};

private:
	const std::string _name;
	bool _isSigned;
	const int _gradeSign;
	const int _gradeExecute;
};

std::ostream & operator << (std::ostream &out, const Form &Form);

#endif //EX01_FORM_H
