#include "ScalarConverter.hpp"


//Constructors

ScalarConverter::ScalarConverter()
{
    std::cout << "Default ScalarConverter constructor called!" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string input) : _input(input)
{
    std::cout << "ScalarConverter constructor called!" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called!" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) : _input(other.getInput())
{
    std::cout << "Copy ScalarConverter constructor called!" << std::endl;
    *this = other;
    printOutput();
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
    if(this != &other)
    {
        this->_type = other.getType();
        this->_char = other.getChar();
        this->_int = other.getInt();
        this->_float = other.getFloat();
        this->_double = other.getDouble();   
    }
    return *this;
}

//Functions
void    ScalarConverter::convert(std::string input)
{
    setInput(input);
    _double = atof(getInput().c_str());
    convertInput();
    printOutput();
}

void    ScalarConverter::setInput(std::string& input)
{
    _input = input;
}

void    ScalarConverter::fromChar()
{
    _char = static_cast<unsigned char>(getInput()[0]);
    _int = static_cast<int>(getChar());
    _float = static_cast<float>(getChar());
    _double = static_cast<double>(getChar());
}

void    ScalarConverter::fromInt()
{  
    _int = static_cast<int>(getDouble());
    _char = static_cast<char>(getInt());
    _float = static_cast<float>(getDouble());
}

void    ScalarConverter::fromFloat()
{
    _float = static_cast<float>(getDouble());
    _char = static_cast<char>(getFloat());
    _int = static_cast<int>(getFloat());
}

void    ScalarConverter::fromDouble()
{
    _char = static_cast<char>(getDouble());
    _int = static_cast<int>(getDouble());
    _float = static_cast<float>(getDouble());
}

int ScalarConverter::checkInput()
{
    if (getInput().compare("nan") == 0 || getInput().compare("+inf") == 0 || getInput().compare("-inf") == 0 || getInput().compare("+inff") == 0 || getInput().compare("-inff") == 0)
        return NAN_INF;
    else if (getInput().length() == 1 && (getInput()[0] == '+' || getInput()[0] == '-' || getInput()[0] == 'f' || getInput()[0] == '.'))
        return (CHAR);
    else if (getInput().find_first_of("+-") != getInput().find_last_of("+-"))
        return (ERROR);
    else if (getInput().find_first_not_of("+-0123456789") == std::string::npos)
        return (INT);
    else if (getInput().find_first_not_of("+-0123456789.") == std::string::npos)
    {
        if (getInput().find_first_of(".") != getInput().find_last_of(".") || isdigit(getInput()[getInput().find_first_of(".") + 1]) == false || getInput().find_first_of(".") == 0)
            return (ERROR);
        else
            return (DOUBLE);
    }
    else if (getInput().find_first_not_of("+-0123456789.f") == std::string::npos)
    {
        if (getInput().find_first_of(".") != getInput().find_last_of(".") || getInput().find_first_of("f") != getInput().find_last_of("f") || getInput().find_first_of("f") - getInput().find_first_of(".") == 1 || getInput().find_first_of(".") == 0 || getInput()[getInput().find_first_of("f") + 1] != '\0')
            return (ERROR);
        else
            return (FLOAT);
    }
    else if (getInput().length() == 1 && (std::isprint(getInput()[0]) || getInput().length() == 1) && std::isalpha(getInput()[0]))
        return (CHAR);
    else
        return (ERROR);
}

void    ScalarConverter::convertInput()
{
    _type = checkInput();
    if (getType() == NAN_INF)
        return ;
    if (getType() == CHAR)
        fromChar();
    else if (getType() == INT)
        fromInt();
    else if (getType() == FLOAT)
        fromFloat();
    else if (getType() == DOUBLE)
        fromDouble();
    else
        throw ErrorException();
}

void    ScalarConverter::printOutput() const
{
    if (getType() != NAN_INF && getDouble() <= UCHAR_MAX && this->getDouble() >= 0)
    {
        if (isprint(getChar()))
            std::cout << "char: '" << getChar() << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout <<"char: impossible" << std::endl;

    if (getType() != NAN_INF && getDouble() >= std::numeric_limits<int>::min() && getDouble() <= std::numeric_limits<int>::max())
        std::cout <<  "int: " << getInt() << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    if (getType() != NAN_INF)
    {
        std::cout << "float: " << getFloat();
        if (getFloat() - getInt() == 0)
            std::cout << ".0f" << std::endl;
        else
            std::cout << "f" << std::endl;
    }
    else
    {
        if (getInput() == "nan" || getInput() == "nanf")
            std::cout << "float: nanf" << std::endl;
        else if (getInput()[0] == '+')
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
    }

    if(getType() != NAN_INF)
    {
        std::cout << "double: " << getDouble();
        if (getDouble() < std::numeric_limits<int>::min() || getDouble() > std::numeric_limits<int>::max() || getDouble() - getInt() == 0)
            std::cout << ".0" << std::endl;
        else
            std::cout << std::endl;
    }      
    else
    {   if (getInput() == "nan" || getInput() == "nanf")
            std::cout << "double: nan" <<std::endl;
        else if (getInput()[0] == '+')
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    }
}


//Getters
std::string     ScalarConverter::getInput() const
{
    return _input;
}

int ScalarConverter::getType() const
{
    return _type;
}

char    ScalarConverter::getChar() const
{
    return _char;
}

int     ScalarConverter::getInt () const
{
    return _int;
}

float   ScalarConverter::getFloat() const
{
    return _float;
}

double  ScalarConverter::getDouble() const
{
    return _double;
}