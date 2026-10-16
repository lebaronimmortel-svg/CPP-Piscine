#include "ClapTrap.hpp"

            ClapTrap::ClapTrap(void) : _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

            ClapTrap::ClapTrap(const std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

            ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

void        ClapTrap::attack(const std::string& target)
{
    if (_hit_points != 0 && _energy_points != 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage" << std::endl;
        _energy_points -= 1;
    }
}

void        ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage " << std::endl;
    if (amount <= _hit_points)
        _hit_points -= amount;
    else
        _hit_points = 0;
}

void        ClapTrap::beRepaired(unsigned int amount)
{
    if (_hit_points != 0 && _energy_points != 0)
    {
        std::cout << "ClapTrap " << _name << " recovers " << amount << " health points " << std::endl;
        _hit_points += amount;
        _energy_points -= 1;
    }
}

std::string ClapTrap::getName(void) const
{
    return (_name);
}

int         ClapTrap::getHitPts(void) const
{
    return (_hit_points);
}

int         ClapTrap::getEnergyPts(void) const
{
    return (_energy_points);
}

int         ClapTrap::getAtkDmg(void) const
{
    return (_attack_damage);
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& rhs)
{
    if (this != &rhs)
    {
        _name = rhs.getName();
        _hit_points = rhs.getHitPts();
        _energy_points = rhs.getEnergyPts();
        _attack_damage = rhs.getAtkDmg();
    }

    return *this;
}

            ClapTrap::ClapTrap(const ClapTrap& copy)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = copy;
}
