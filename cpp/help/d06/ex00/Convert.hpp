/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:51:22 by drayl             #+#    #+#             */
/*   Updated: 2022/03/27 19:51:23 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP
# define VALUE_COUNT 4
# define INVALID "impossible!"
# define INVALID_SYMBOL "Non displayable"
#include <iostream>

enum type {
    E_INT = 0,
    E_CHAR = 1,
    E_FLOAT = 2,
    E_DOUBLE = 3
};

enum specString {
    E_NAN = 0,
    E_INF = 1,
    E_NEG_INF = 2,
    E_DEFAULT = 3
};

int specString(const std::string &string);
int findAccuracy(char *str);
bool validString(char *str);
bool isSymbol(const char *str);

class Convert {
private:
    int _accuracy;
    std::string _string;
    bool flags[VALUE_COUNT];

    int _int;
    char _char;
    float _float;
    double _double;

    void setInt(const char *input);
    void setChar(const char *input);
    void setFloat(const char *input);
    void setDouble(const char *input);

    void printInt();
    void printChar();
    void printFloat();
    void printDouble();

    Convert() {};
public:
    Convert(char *input);
    Convert(const Convert &element);
    ~Convert();

    Convert &operator=(const Convert &element);

    void printValue();
};

#endif
