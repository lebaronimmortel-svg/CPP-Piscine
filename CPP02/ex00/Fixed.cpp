/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called !" << "\n";
    *this = copy;
}

Fixed::Fixed(void) : val(0)
{
    std::cout << "Default constructor called !" << "\n";
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called !" << "\n";
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    if (this != &rhs)
    {
        this->val = rhs.getRawBits();
    }

    return *this;
}

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called !" << "\n";
    return (this->val);
}

void     Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called !" << "\n";
    this->val = raw;
}
