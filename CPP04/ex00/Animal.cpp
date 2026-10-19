/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal() : _type("none")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const
{
    return (_type);
}

Animal& Animal::operator=(const Animal& rhs)
{
    if (this != &rhs)
    {
        _type = rhs.getType();
    }

    return *this;
}

Animal::Animal(const Animal& copy) : _type(copy._type)
{
    std::cout << "Animal copy constructor called" << "\n";
}

void Animal::makeSound() const 
{
    std::cout << "- Generic Animal sound -" << std::endl;
}
