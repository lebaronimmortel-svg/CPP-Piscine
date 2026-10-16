#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Utils.cpp"

int main()
{
    std::cout << std::endl << BOLD << BLUE << "[Basic tests]" << RESET << std::endl << std::endl;

	std::srand(time(NULL));

    Base* c = new C;
    identify(c);

    B a;
    identify(a);

    std::cout << std::endl << BOLD << BLUE << "[Random loop/generation tests]" << RESET << std::endl << std::endl;

    for (int i = 0; i < 10; i++)
    {
        Base* random = generate();
        identify(random);
    }

    std::cout << std::endl;
}
