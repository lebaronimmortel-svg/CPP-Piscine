/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string& name) : _type(name)
{
    std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(void) : _type("unknown")
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria destructor called" << std::endl;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "Using a non-effect item on" << target.getName() << std::endl; 
}

const std::string& AMateria::getType(void) const
{
    return (_type);
}

AMateria::AMateria(const AMateria& copy) : _type(copy._type)
{
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
    std::cout << "AMateria operator= called" << std::endl;
    if (this != &rhs)
    {
        _type = rhs.getType();
    }
    return *this;
}