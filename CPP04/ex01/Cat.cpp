#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
    _brain = new Brain;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

Cat& Cat::operator=(const Cat& rhs)
{
    std::cout << "Cat operator= called" << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        *this->_brain = *rhs._brain;
    }
    return *this;
}

std::string Cat::getIdea(int i)
{
    return (_brain->getIdea(i));
}

void Cat::setIdea(int i, const std::string idea)
{
    _brain->setIdea(i, idea);
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->_brain = new Brain (*copy._brain);
}

void Cat::makeSound(void) const
{
    std::cout << _type << " : Meow" << std::endl;
}