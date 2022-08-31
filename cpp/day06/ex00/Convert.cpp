#include <iomanip>
#include "Convert.hpp"

//   --- Constructor/Destructor ---   //

Convert::Convert(char *input) {
    this->flags[0] = validString(input);
        for (int i = 1; i < VALUE_COUNT; ++i) {
            this->flags[i] = this->flags[0];
        }
    setInt(input);
    setChar(input);
    setFloat(input);
    setDouble(input);
    this->_string = input;
    this->_accuracy = findAccuracy(input);
}

Convert::Convert(const Convert &element) { *this = element; }

Convert::~Convert() {}


//   --- Override operator ---   //

Convert &Convert::operator=(const Convert &element) {
    this->_int = element._int;
    this->_char = element._char;
    this->_float = element._float;
    this->_double = element._double;
    this->_string = element._string;
    this->_accuracy = element._accuracy;
    for (int i = 0; i < VALUE_COUNT; ++i) {
        this->flags[i] = element.flags[i];
    }
    return (*this);
}

//   --- Setters ---   //

void Convert::setInt(const char *input) {
    try {
        if (isSymbol(input))
            this->_int = *input;
        else
            this->_int = static_cast<int>(std::stoi(input));
    } catch (...) {
        this->flags[E_INT] = false;
    }
}

void Convert::setChar(const char *input) {
    try {
        if (isSymbol(input))
            this->_char = *input;
        else
            this->_char = static_cast<char>(std::stoi(input));
    } catch (...) {
        this->flags[E_CHAR] = false;
    }
}

void Convert::setFloat(const char *input) {
    try {
        if (isSymbol(input))
            this->_float = *input;
        else
            this->_float = static_cast<float>(std::stof(input));
    } catch (...) {
        switch (specString(this->_string)) {
            case  E_NAN:
                this->_float = (0 / 0);
                break;
            case E_INF :
                this->_float = (1 / 0);
                break;
            case E_NEG_INF :
                this->_float = (-1 / 0);
                break;
            default:
                this->flags[E_FLOAT] = false;
                break;
        }
    }
}

void Convert::setDouble(const char *input) {
    try {
        if (isSymbol(input))
            this->_double = *input;
        else
            this->_double = static_cast<double>(std::stod(input));
    } catch (...) {
        switch (specString(this->_string)) {
            case  E_NAN:
                this->_double = (0 / 0);
                break;
            case E_INF :
                this->_double = (1 / 0);
                break;
            case E_NEG_INF :
                this->_double = (-1 / 0);
                break;
            default:
                this->flags[E_DOUBLE] = false;
                break;
        }
    }
}

//   --- Prints ---   //

void Convert::printValue() {
    printChar();
    printInt();
    printFloat();
    printDouble();
}

void Convert::printInt() {
    std::cout << "int: ";
    if (this->flags[E_INT])
        std::cout << this->_int << std::endl;
    else
        std::cout << INVALID << std::endl;
}

void Convert::printChar() {
    std::cout << "char: ";
    if (!this->flags[E_CHAR])
        std::cout << INVALID << std::endl;
    else if (!isprint(this->_char))
        std::cout << INVALID_SYMBOL << std::endl;
    else
        std::cout << "'" <<this->_char << "'" << std::endl;
}

void Convert::printFloat() {
    std::cout << "float: ";
    std::cout << std::fixed <<  std::setprecision(this->_accuracy);
    if (this->flags[E_FLOAT])
        std::cout << this->_float << "f" << std::endl;
    else
        std::cout << INVALID << std::endl;
}

void Convert::printDouble() {
    std::cout << "double: ";
    std::cout << std::fixed <<  std::setprecision(this->_accuracy);
    if (this->flags[E_DOUBLE])
        std::cout << this->_double << std::endl;
    else
        std::cout << INVALID << std::endl;
}



