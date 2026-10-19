/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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