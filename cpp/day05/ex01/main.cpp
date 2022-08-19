#include "Bureaucrat.h"
#include "Form.h"

int main(void) {
	Bureaucrat bureaucrat("Mick", 2);

	std::cout << "***************" << std::endl;
	try {
		Form form1;
		std::cout << form1;
		bureaucrat.signForm(form1);
		std::cout << form1;
		std::cout << "***************" << std::endl;
		Form form2("form2", 17);
		std::cout << form2;
		bureaucrat.signForm(form2);
		std::cout << form2;
		std::cout << "***************" << std::endl;
		Form form3("form3", 163);
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	std::cout << "***************" << std::endl;
	try {
		Form form("form4", 142, 0);
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	std::cout << "***************" << std::endl;
	try {
		Form form("form5", 192, 0);
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
}