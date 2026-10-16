#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
    (void) copy;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& rhs)
{
    (void) rhs;
    std::cout << "Intern operator= called" << std::endl;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(std::string form_name, std::string form_target)
{
    std::string array[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    unsigned int i = 0;
    AForm* form = NULL;

    while (i < 3)
    {
        if (array[i] == form_name)
            break ;
        i++;
    }
    switch (i) 
    {
        case 0:
            form = new ShrubberyCreationForm(form_target);
            break;
        case 1:
            form = new RobotomyRequestForm(form_target);
            break;
        case 2:
            form = new PresidentialPardonForm(form_target);
            break;
        default:
            std::cerr << "Couldn't create " << form_name << " : unknown form type" << std::endl;
            break;
    }

    if (i < 3)
            std::cout << "Intern creates " << form_name << std::endl;
   return (form);
}