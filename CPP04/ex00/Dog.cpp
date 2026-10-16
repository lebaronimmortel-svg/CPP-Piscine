#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
    std::cout << "Dog operator= called" << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
    }

    return *this;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << _type << " : Wouf" << std::endl;
}