#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:

        int                 val;
        static const int    frac;

    public:

        Fixed();
        Fixed(const Fixed& copy);
        ~Fixed();
        Fixed(const int var1);
        Fixed(const float var2);
        
        int     			    getRawBits(void) const;
        void    			    setRawBits(int const raw);
        float   			    toFloat(void) const;
        int     			    toInt(void) const;
        
        Fixed&                  operator=(const Fixed& rhs);
       	int                     operator>(const Fixed& rhs) const;
        int                     operator<(const Fixed& rhs) const;
        int                     operator>=(const Fixed& rhs) const;
        int                     operator<=(const Fixed& rhs) const;
        int                     operator==(const Fixed& rhs) const;
        int                     operator!=(const Fixed& rhs) const;

        Fixed                   operator+(const Fixed& rhs) const;
        Fixed                   operator-(const Fixed& rhs) const;
        Fixed                   operator*(const Fixed& rhs) const;
        Fixed                   operator/(const Fixed& rhs) const;

        Fixed&                  operator++(void);
        Fixed                   operator++(int);
        Fixed&                  operator--(void);
        Fixed                   operator--(int);

        static Fixed&           min(Fixed& one, Fixed& two);
        static const Fixed&     min(const Fixed& one, const Fixed& two);
        static Fixed&           max(Fixed& one, Fixed& two);
        static const Fixed&     max(const Fixed& one, const Fixed& two);
};

std::ostream& operator<<(std::ostream& os, const Fixed& rhs);

#endif
