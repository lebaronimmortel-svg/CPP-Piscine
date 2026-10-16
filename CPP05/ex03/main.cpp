#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() 
{
    Intern someRandomIntern;
    AForm* form_1;
    form_1 = someRandomIntern.makeForm("presidential pardon", "Bender");
    std::cout << *form_1 << std::endl;

    std::cout << std::endl << std::endl;

    AForm* form_2;
    form_2 = someRandomIntern.makeForm("robotomy request", "Sullyvan");
    std::cout << *form_2 << std::endl;

    std::cout << std::endl << std::endl;

    AForm* form_3;
    form_3 = someRandomIntern.makeForm("shrubbery creation", "Ornella");
    std::cout << *form_3 << std::endl;

    std::cout << std::endl << std::endl;

    AForm* form_4;
    form_4 = someRandomIntern.makeForm("car rent", "Patricia");

    std::cout << std::endl << std::endl;
    
    delete form_1;
    delete form_2;
    delete form_3;
}