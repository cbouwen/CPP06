#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Default constructor called!" << std::endl;
}

Serializer::~Serializer()
{
    std::cout << "Destructor called!" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
    *this = other;
    std::cout << "Copy constructor called!" << std::endl;
}

Serializer& Serializer::operator=(const Serializer &other)
{
    if(this != &other)
    {
    }
    return *this;
}

Data*   Serializer::deserializer(uintptr_t serializedAddress)
{
    return reinterpret_cast<Data*>(serializedAddress);
}

uintptr_t   Serializer::serializer(Data *ptrToData)
{
    return  reinterpret_cast<uintptr_t>(ptrToData);
}