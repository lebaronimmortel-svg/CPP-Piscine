#include "ScavTrap.hpp"

int main()
{
///////////////////////////// TEST 1 ////////////////////////////////////////
    
    std::cout << :: std::endl;
    std::cout << "Creating a new instance a" << std::endl;

    ScavTrap a("'ScavTrap a'");

    std::cout << :: std::endl;
    std::cout << "Testing instance a's attributes" << std::endl;
    std::cout << :: std::endl;

    a.attack("Aux1");
    std::cout << "Instance a hit points : " << a.getHitPts() << std::endl;
    std::cout << :: std::endl;
    a.takeDamage(15);
    std::cout << "Instance a hit points : " << a.getHitPts() << std::endl;
    std::cout << :: std::endl;
    a.beRepaired(128);
    std::cout << "Instance a hit points : " << a.getHitPts() << std::endl;
    std::cout << :: std::endl;
    a.guardGate();

///////////////////////////// TEST 2 ////////////////////////////////////////

    std::cout << :: std::endl;
    std::cout << "Creating a new instance c by copying a" << std::endl;

    ScavTrap c(a);

    std::cout << :: std::endl;
    std::cout << "Instance c name : " << c.getName() << std::endl;
    std::cout << "Instance c hit points : " << c.getHitPts() << std::endl;
    std::cout << "Instance c energy points : " << c.getEnergyPts() << std::endl;
    std::cout << "Instance c attack damages : " << c.getAtkDmg() << std::endl;

///////////////////////////// TEST 3 ////////////////////////////////////////
    
    std::cout << :: std::endl;
    std::cout << "Creating a new instance b" << std::endl;

    ScavTrap b("'ScavTrap b'");

    std::cout << :: std::endl;
    std::cout << "Assigning a = b" << std::endl;
    a = b;
    std::cout << :: std::endl;

    std::cout << "Instance a name : " << a.getName() << std::endl;
    std::cout << "Instance a hit points : " << a.getHitPts() << std::endl;
    std::cout << "Instance a energy points : " << a.getEnergyPts() << std::endl;
    std::cout << "Instance a attack damages : " << a.getAtkDmg() << std::endl;

    std::cout << :: std::endl;
    std::cout << "End of program" << std::endl;
    std::cout << :: std::endl;
    return (0);
}