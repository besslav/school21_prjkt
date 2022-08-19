//
// Created by Price Skip on 8/19/22.
//

#ifndef EX00_BUREAUCRAT_H
#define EX00_BUREAUCRAT_H

#include <iostream>

class Bureaucrat {
private:
	std::string const _name;
	int 		_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string const&, int);
	Bureaucrat(Bureaucrat const &);
	Bureaucrat& operator=(Bureaucrat const &);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void incGrade();
	void decGrade();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream & operator << (std::ostream &out, const Bureaucrat &bureaucrat);
#endif //EX00_BUREAUCRAT_H
