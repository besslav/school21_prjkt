#include "Convert.hpp"

int specString(const std::string &string) {
    if (string == "nan")
        return (E_NAN);
    if (string == "inf")
        return (E_INF);
    if (string == "-inf")
        return (E_NEG_INF);
    return (E_DEFAULT);
}

int findAccuracy(char *str) {
    int accuracy = 0;

    if (*str == '-')
        ++str;
    while (isdigit(*str))
        ++str;
    if (*str != '.')
        return (1);
    while (isdigit(*(++str)))
        ++accuracy;
    return (accuracy + (accuracy == 0));
}

bool isSymbol(const char *str) {
    return (*str == '\0' || (!isdigit(*str) && *(str + 1) == '\0'));
}

bool validString(char *str) {
    if (isSymbol(str))
        return (true);
    if (specString(str) != E_DEFAULT)
        return (true);
    if (*str == '-')
        ++str;
    if (!isdigit(*str))
        return (false);
    while (isdigit(*str))
        ++str;
    if (*str == '.')
        ++str;
    while (isdigit(*str))
        ++str;
    if (*str == 'f')
        ++str;
    if (*str != '\0')
        return (false);
    return (true);
}
