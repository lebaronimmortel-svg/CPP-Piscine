#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    int rand = std::rand() % 3;
    Base* ptr = NULL;

    if (rand == 0)
        ptr = new A;
    else if (rand == 1)
        ptr = new B;
    else if (rand == 2)
        ptr = new C;
    return (ptr);
}

void identify(Base* p)
{
    A* ptr_a = dynamic_cast<A*>(p);
    B* ptr_b = dynamic_cast<B*>(p);
    C* ptr_c = dynamic_cast<C*>(p);

    if (ptr_a && !ptr_b && !ptr_c)
        std::cout << "Identified type A" << std::endl;
    else if (!ptr_a && ptr_b && !ptr_c)
        std::cout << "Identified type B" << std::endl;
    else if (!ptr_a && !ptr_b && ptr_c)
        std::cout << "Identified type C" << std::endl;
    else
        std::cout << "Unknown object" << std::endl;
}

void identify(Base& p)
{
    unsigned int flag = 0;

    try
    {
        A& ref_a = dynamic_cast<A&>(p);
        (void) ref_a;
    }
    catch (const std::exception& e)
    {
        flag++;
        try
        {
            B& ref_b = dynamic_cast<B&>(p);
            (void) ref_b;
        }
        catch (const std::exception& e)
        {
            flag++;
            try
            {
                C& ref_c = dynamic_cast<C&>(p);
                (void) ref_c;
            }
            catch (const std::exception& e)
            {
                flag++;
            }
        }
    }
    if (flag == 0)
        std::cout << "Identified type A" << std::endl;
    else if (flag == 1)
        std::cout << "Identified type B" << std::endl;
    else if (flag == 2)
        std::cout << "Identified type C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}