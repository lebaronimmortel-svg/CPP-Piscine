#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:

        int                 val;
        static const int    frac;

    public:

        Fixed();
        Fixed(const Fixed& copy);
        Fixed& operator=(const Fixed& rhs);
        ~Fixed();
        
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif
