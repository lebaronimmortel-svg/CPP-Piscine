#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria
{
    public :

        Cure();
        ~Cure();
        Cure& operator=(const Cure& rhs);
        Cure(const Cure& copy);
        AMateria* clone() const;
        void use(ICharacter& target);
        void use(int index, ICharacter& target);
};

#endif