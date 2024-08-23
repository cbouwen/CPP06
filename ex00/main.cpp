#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        std::cout << "Give 1 argument please" << std::endl;
        return (1);
    }
    std::string inputStr = (argv[1]);
    ScalarConverter::convert(inputStr);
    return 0;
}