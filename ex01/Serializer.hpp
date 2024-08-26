#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

typedef struct Data
{
    std::string     name;
    int             age;
}          Data;


class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer& other);
        ~Serializer();
        Serializer& operator=(const Serializer& other);


    protected:

    public:
        static uintptr_t   serializer(Data* ptrToData);
        static Data*        deserializer(uintptr_t SerializerdAddress);

};

#endif