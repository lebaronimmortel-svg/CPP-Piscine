/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
    _brain = new Brain; 
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}

Dog& Dog::operator=(const Dog& rhs)
{
    std::cout << "Dog operator= called" << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        *this->_brain = *rhs._brain;
    }
    return *this;
}

std::string Dog::getIdea(int i)
{
    return (_brain->getIdea(i));
}

void Dog::setIdea(int i, std::string idea)
{
    _brain->setIdea(i, idea);
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = new Brain (*copy._brain);
}

void Dog::makeSound(void) const
{
    std::cout << _type << " : Wouf" << std::endl;
}