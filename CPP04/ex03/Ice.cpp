#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice(void)
{
    std::cout << "Ice destructor called" << std::endl;
}

void Ice::use(ICharacter& target) 
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone(void) const
{
    Ice* copy = new Ice(*this);
    return copy;
}

Ice& Ice::operator=(const Ice& rhs)
{
    if (this != &rhs)
    {
        AMateria::operator=(rhs);
    }
    return *this;
}

Ice::Ice(const Ice& copy)
{
    std::cout << "Ice copy constructor called" << std::endl;
    this->_type = copy._type;
}