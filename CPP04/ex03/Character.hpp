#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private :

        std::string _name;
        AMateria** _inventory;
        int _n_unequiped;
        AMateria** _unequiped;

    public:
    
        Character();
        Character(std::string name);
        virtual ~Character();
        Character(const Character& copy);
        Character& operator=(const Character& copy);
        const std::string& getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif


