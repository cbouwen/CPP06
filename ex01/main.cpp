#include "Serializer.hpp"

int main()
{
    Data    *student1 = new Data;
    Data    *student2 = new Data;

    student1->name = "John";
    student1->age = 30;

    student2->name = "Jack";
    student2->age = 22;

    uintptr_t serializedAddress1 = Serializer::serializer(student1);
    uintptr_t serializedAddress2 = Serializer::serializer(student2);

    Data *serializedData1 = Serializer::deserializer(serializedAddress1);
    Data *serializedData2 = Serializer::deserializer(serializedAddress2);

    std::cout << "Original data of student 1: " << student1->name << " Age: " << student1->age << std::endl;
    std::cout << "Deserialized data of student 1: " << serializedData1->name << " Age: " << serializedData1->age << std::endl;
    std::cout << "Original data of student 2: " << student2->name << " Age: " << student2->age << std::endl;
    std::cout << "Deserialized data of student 2: " << serializedData2->name << " Age: " << serializedData2->age << std::endl;

    delete  student1;
    delete  student2;
}