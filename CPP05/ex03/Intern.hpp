#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public :

        Intern();
        Intern(const Intern& copy);
        Intern& operator= (const Intern& rhs);
        ~Intern();

        AForm* makeForm(std::string form_name, std::string form_target);
};

#endif



