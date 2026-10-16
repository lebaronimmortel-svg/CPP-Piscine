#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal() 
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (_type);
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    std::cout << "WrongAnimal operator= called" << std::endl;
    if (this != &rhs)
    {
        _type = rhs.getType();
    }

    return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : _type(copy._type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

void WrongAnimal::makeSound() const 
{
    std::cout << "- Generic Animal sound -" << std::endl;
}
