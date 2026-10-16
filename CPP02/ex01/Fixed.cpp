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
    std::cout << "Copy assignment operator called !" << "\n";
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
    std::cout << "Float constructor called !" << "\n";
    val = roundf(var2 * (1 << frac));
}

Fixed::Fixed(const int var1)
{
    std::cout << "Int constructor called !" << "\n";
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
