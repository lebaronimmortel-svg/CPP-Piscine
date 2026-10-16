#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure(void)
{
    std::cout << "Cure destructor called" << std::endl;
}

void Cure::use(ICharacter& target) 
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone(void) const
{
    Cure* copy = new Cure(*this);
    return copy;
}

Cure& Cure::operator=(const Cure& rhs)
{
    if (this != &rhs)
    {
        AMateria::operator=(rhs);
    }
    return *this;
}

Cure::Cure(const Cure& copy)
{
    std::cout << "Cure copy constructor called" << std::endl;
    this->_type = copy._type;
}