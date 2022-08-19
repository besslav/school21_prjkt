#include "Bureaucrat.h"

int main() {
	Bureaucrat bureaucrat1;
	//bureaucrat1.incGrade();
	std::cout << bureaucrat1;
	//bureaucrat1.decGrade();
	try {
		bureaucrat1.decGrade();
	} catch (int const str) {
		std::cout << str << std::endl;
	}
	std::cout << "***************" << std::endl;
	try {
		Bureaucrat bureaucrat2("Mick", 1);
		std::cout << bureaucrat2;
		bureaucrat2.incGrade();
		std::cout << bureaucrat2;
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	std::cout << "***************" << std::endl;
	try {
		Bureaucrat bureaucrat3("Lilli", 0);
		std::cout << bureaucrat3;
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	std::cout << "***************" << std::endl;
	try {
		Bureaucrat bureaucrat4("Dory", 171);
		std::cout << bureaucrat4;
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
}
