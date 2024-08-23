#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <cstdlib>
#include <locale>
#include <cmath>
#include <cstdio>

enum    e_type
{
    INVALID = -1,
    PSEUDO = 0,
    CHAR = 1,
    INT = 2,
    FLOAT = 3,
    DOUBLE = 4
};

class   ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator = (const ScalarConverter& other);
        ~ScalarConverter();

        static e_type typeIdentifier(std::string& input);

    public:
        static void convert(std::string& input);

};

#endif