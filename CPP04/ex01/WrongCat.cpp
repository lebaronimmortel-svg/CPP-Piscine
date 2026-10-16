#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat")
{
    std::cout << "WrongCat constructor called" << std::endl;
    _brain = new Brain;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
    delete _brain;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    std::cout << "WrongCat operator= called" << std::endl;
    if (this != &rhs)
    {
        WrongAnimal::operator=(rhs);
    }

    return *this;
}

void WrongCat::setIdea(int i, const std::string idea)
{
    _brain->setIdea(i, idea);
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->_brain = copy._brain;
}

void WrongCat::makeSound(void) const
{
    std::cout << _type << " : WrongMeow" << std::endl;
}

std::string WrongCat::getIdea(int i)
{
    return (_brain->getIdea(i));
}