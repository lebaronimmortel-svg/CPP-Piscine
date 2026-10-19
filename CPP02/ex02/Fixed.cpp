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
    *this = copy;
}

Fixed::Fixed(void) : val(0) {}

Fixed::~Fixed(void){}

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
    return (val);
}

void     Fixed::setRawBits(int const raw)
{
    val = raw;
}

Fixed::Fixed(const float var2)
{
    val = roundf(var2 * (1 << frac));
}

Fixed::Fixed(const int var1)
{
    val = var1 * (1 << frac);
}

float Fixed::toFloat(void) const
{
    return ((float)this->val / (1 << frac));
}

int Fixed::toInt(void) const
{
    return (this->val / (1 << frac));
}

std::ostream& operator<<(std::ostream& os, const Fixed& rhs)
{
    os << rhs.toFloat();

    return (os);
}

int Fixed::operator>(const Fixed& rhs) const
{
	if (this->getRawBits() > rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<(const Fixed& rhs) const
{
	if (this->getRawBits() < rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator>=(const Fixed& rhs) const
{
	if (this->getRawBits() >= rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<=(const Fixed& rhs) const
{
	if (this->getRawBits() <= rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator==(const Fixed& rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator!=(const Fixed& rhs) const
{
	if (this->getRawBits() != rhs.getRawBits())
		return (1);
	return (0);
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
    Fixed result;
    
    result.setRawBits(this->getRawBits() + rhs.getRawBits());
    
    return (result);
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
    Fixed result;
    
    result.setRawBits(this->getRawBits() - rhs.getRawBits());
    
    return (result);
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    Fixed result;
    
    result.setRawBits(this->getRawBits() * rhs.getRawBits() / (1 << frac));
    
    return (result);
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
    Fixed result;
    
    result.setRawBits((this->getRawBits() * (1 << frac)) / rhs.getRawBits());
    
    return (result);
}

Fixed& Fixed::operator++(void)
{
    this->val += 1;  

    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed copie(*this);
    this->val += 1;    
 
    return (copie);       
}

Fixed& Fixed::operator--(void)
{
    this->val -= 1;  

    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed copie(*this);
    this->val -= 1;  
 
    return (copie);       
}

Fixed&  Fixed::min(Fixed& one, Fixed& two)
{
    if (one > two)
        return (two);
    return (one);
}

const Fixed&  Fixed::min(const Fixed& one, const Fixed& two)
{
    if (one > two)
        return (two);
    return (one);
}

Fixed&  Fixed::max(Fixed& one, Fixed& two)
{
    if (one < two)
        return (two);
    return (one);
}

const Fixed&  Fixed::max(const Fixed& one, const Fixed& two)
{
    if (one < two)
        return (two);
    return (one);
}
