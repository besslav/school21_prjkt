

#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137),
                                             _target("default_shrubbery") {
    std::cout << "Default constructor ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
        AForm("ShrubberyCreationForm", 145, 137), _target(target + "_shrubbery") {
    std::cout << "Constructor ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy),
                                                                            _target(copy.getTarget()) {
    std::cout << "Copy constructor ShrubberyCreationForm " << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    std::cout << "Copy operator ShrubberyCreationForm" << std::endl;
    _target = copy.getTarget();
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Destructor ShrubberyCreationForm" << std::endl;
}

void ShrubberyCreationForm::beExecute(Bureaucrat &bureaucrat) {
    AForm::beExecute(bureaucrat);

    std::ofstream newFile(_target.c_str());
    if(newFile.is_open() == 0)
        throw ShrubberyCreationForm::CreatedFileException();
    newFile << "               ,@@@@@@@,\n"
               "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
               "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
               "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
               "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
               "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
               "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
               "       |o|        | |         | |\n"
               "       |.|        | |         | |\n"
               "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

const char *ShrubberyCreationForm::CreatedFileException::what() const throw() {
    return "Error created file";
}