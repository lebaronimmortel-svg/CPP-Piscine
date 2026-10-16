#include "ScavTrap.hpp"

            ScavTrap::ScavTrap(void)
{
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;   
    std::cout << "ScavTrap default constructor called" << std::endl;
}

            ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;   
    std::cout << "ScavTrap constructor called" << std::endl;
}

            ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void        ScavTrap::attack(const std::string& target)
{
    std::cout << "ScavTrap " << _name << " slashes " << target << ", causing " << _attack_damage << " points of damage" << std::endl;
}

void        ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& rhs)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
    }
    return *this;
}

            ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}
