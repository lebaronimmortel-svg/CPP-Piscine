#include <iostream>

class ClapTrap
{
    protected :

        std::string          _name;
        unsigned int         _hit_points;
        unsigned int         _energy_points;
        unsigned int         _attack_damage;

    public :

                    ClapTrap    ();
                    ClapTrap    (const std::string name);
                    ClapTrap    (const ClapTrap& copy);
        ClapTrap&   operator=   (const ClapTrap& rhs);
                    ~ClapTrap   ();

        std::string getName     () const;
        int         getHitPts   () const;
        int         getEnergyPts() const;
        int         getAtkDmg   () const;

        void        attack      (const std::string& target);
        void        takeDamage  (unsigned int amount);
        void        beRepaired  (unsigned int amount);
};