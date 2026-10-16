#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
    private:

        AMateria** _learntMaterias;

    public:

        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource& copy);
        MateriaSource& operator=(const MateriaSource& rhs);
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif