#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base    *generate(void)
{
    srand(time(NULL));
    int randomSeed = rand() % 3;

    if (randomSeed == 0)
        return new A();
    else if (randomSeed == 1)
        return new B();
    else
        return new C();
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type C" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "Type A" << std::endl;
        (void)a;
    }
    catch (std::exception&)
    {
        try
        {
            B& b = dynamic_cast<B&>(p);
            std::cout << "Type B" << std::endl;
            (void)b;
        }
        catch (std::exception)
        {
            C& c = dynamic_cast<C&>(p);
            std::cout << "Type C" << std::endl;
            (void)c;
        }
    }
}

int     main(void)
{
    Base    *baseClass;
    baseClass = generate();

    identify(baseClass);
    identify(*baseClass);
}