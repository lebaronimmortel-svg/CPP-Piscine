#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int i) const
{ 
    return (_ideas[i]);
}

Brain& Brain::operator=(const Brain& rhs)
{
    std::cout << "Brain operator= called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
            _ideas[i] = rhs.getIdea(i);
    }

    return *this;
}

void Brain::setIdea(int i, std::string idea)
{
    if (i >= 0 && i < 100)
        _ideas[i] = idea;
}

            Brain::Brain(const Brain& copy)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        _ideas[i] = copy.getIdea(i);
    }
}