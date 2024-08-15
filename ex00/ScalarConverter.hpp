#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <cstdlib>

#define NAN_INF 1
#define ERROR 2
#define CHAR 3
#define INT 4
#define FLOAT 5
#define DOUBLE 6


class ScalarConverter
{
    private:
        std::string   _input;
        int                 _type;
        char                _char;
        int                 _int;
        float               _float;
        double              _double;

    protected:

    public:
        //Constructors
        ScalarConverter();
        ScalarConverter(const std::string input);

        //Copy Constructor
        ScalarConverter(const ScalarConverter& other);

        //Destructor
        ~ScalarConverter();

        //Copy assignment operator
        ScalarConverter& operator=(const ScalarConverter& other);

        //Getters
        std::string getInput() const;
        int         getType() const;
        char        getChar() const;
        int         getInt() const;
        float       getFloat() const;
        double      getDouble() const;

        //Setters
        void        setInput(std::string& input);

        //Functions
        void    fromChar();
        void    fromInt();
        void    fromFloat();
        void    fromDouble();

        static void    convert(const std::string input);
        int     checkInput();
        void    convertInput();
        void    printOutput() const;


        //Exceptions
        class ErrorException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Error: Not convertable");
                }
        };
};

#endif