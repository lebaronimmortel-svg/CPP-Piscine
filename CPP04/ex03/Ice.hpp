#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria
{
    public :

        Ice();
        ~Ice();
        Ice& operator=(const Ice& rhs);
        Ice(const Ice& copy);
        AMateria* clone() const;
        void use(ICharacter& target);
        void use(int index, ICharacter& target);
};

#endif