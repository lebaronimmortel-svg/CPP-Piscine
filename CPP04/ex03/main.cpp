#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

#define RESET   "\033[0m"      
#define GREEN   "\033[32m"          
#define BLUE    "\033[34m"          
#define BOLD    "\033[1m"

int main()
{
    std::cout << BLUE << BOLD << "=== TEST 0 : ORTHODOX FORM (AMATERIA) ===" << RESET << std::endl;

    std::cout << std::endl;
    std::cout << GREEN << "** Creating a static Ice w **" << RESET << std::endl; 
    Ice w;

    std::cout << std::endl;
    std::cout << GREEN << "** Creating a static Ice x by copying w **" << RESET << std::endl; 
    Ice x(w);

    std::cout << std::endl;
    std::cout << GREEN << "** Creating a static Ice z then overloading it from w **" << RESET << std::endl;  
    Ice z;
    z = w;

    std::cout << std::endl;
    std::cout << GREEN <<  "** Making all print their types **" << RESET << std::endl;
    std::cout << "w type : "  << w.getType() << std::endl;
    std::cout << "x type : "  << x.getType() << std::endl;
    std::cout << "z type : "  << z.getType() << std::endl;

    std::cout << BLUE << BOLD << "\n=== TEST 1 : ORTHODOX FORM (CHARACTER) ===" << RESET << std::endl;

    std::cout << std::endl;
    std::cout << GREEN <<  "** Creating a static Character aw called 'François' **" << RESET << std::endl; 
    Character aw("François");

    std::cout << std::endl;
    std::cout << GREEN <<  "** Creating a static Character ax by copying aw **" << RESET << std::endl; 
    Character ax(aw);

    std::cout << std::endl;
    std::cout << GREEN <<  "** Creating a static Character az then overloading it from aw **" << RESET << std::endl;  
    Character az;
    az = aw;

    std::cout << std::endl;
    std::cout << GREEN <<  "** Making all three print their names **" << RESET << std::endl;
    std::cout << "aw name : "  << aw.getName() << std::endl;
    std::cout << "ax name : "  << ax.getName() << std::endl;
    std::cout << "az name : "  << az.getName() << std::endl;

    std::cout << BLUE << BOLD << "\n=== TEST 2 : DEEP COPY (CHARACTER) ===" << RESET << std::endl;

    std::cout << std::endl;
    std::cout << GREEN <<  "** Creating a new source then make it learn 'Ice' and 'Cure' **" << RESET << std::endl; 

    std::cout << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << GREEN <<  "\n** Creating a new character 'Luc' **" << RESET << std::endl;
    Character* luc = new Character("Luc");

    std::cout << GREEN <<  "\n** Equiping Luc new materials **" << RESET << std::endl;
    luc->equip(src->createMateria("ice"));
    luc->equip(src->createMateria("cure"));

    std::cout << GREEN <<  "\n** Cloning Luc to a new character, 'CloneLuc' **" << RESET << std::endl;
    Character* cloneLuc = new Character(*luc);

    std::cout << GREEN <<  "\n** Assigning Luc to an existing character 'Jean' **" << RESET << std::endl;
    Character jean("Jean");
    jean.equip(src->createMateria("ice"));
    jean = *luc;

    std::cout << GREEN <<  "\n** Destruction of the original (Luc) **" << RESET << std::endl;
    delete luc;

    std::cout << GREEN <<  "\n** Using clone abilities : **" << RESET << std::endl;
    ICharacter* bob = new Character("Bob");
    
    std::cout << "[CloneLuc] "; cloneLuc->use(0, *bob);
    std::cout << "[CloneLuc] "; cloneLuc->use(1, *bob);
    
    std::cout << "[Jean]     "; jean.use(0, *bob);

    std::cout << GREEN <<  "\n** Final cleaning **" << RESET << std::endl;
    delete bob;
    delete cloneLuc;
    delete src;

    std::cout << BLUE << BOLD << "\n=== TEST 3 : FULL INVENTORY AND GROUND ===" << RESET << std::endl;

    std::cout << std::endl;
    std::cout << GREEN <<  "** Creating a new source then make it learn 'Ice' **" << RESET << std::endl; 

    std::cout << std::endl;
    IMateriaSource* src2 = new MateriaSource();
    src2->learnMateria(new Ice());

    std::cout << std::endl;
    std::cout << GREEN <<  "** Creating a new character 'Warrior' **" << RESET << std::endl; 

    ICharacter* warrior = new Character("Warrior");

    std::cout << std::endl;
    std::cout << GREEN <<  "** Fully populating the inventory **" << RESET << std::endl;
    warrior->equip(src2->createMateria("ice"));
    warrior->equip(src2->createMateria("ice"));
    warrior->equip(src2->createMateria("ice"));
    warrior->equip(src2->createMateria("ice"));

    std::cout << std::endl;
    std::cout << GREEN <<  "** Attempt to equip a 5th item (inventory full) **" << RESET << std::endl;
    AMateria* tooMuch = src2->createMateria("ice");
    warrior->equip(tooMuch); 
    
    delete tooMuch;

    std::cout << std::endl;
    std::cout << GREEN <<  "** Warrior drops the weapon from Slot 1 onto the ground **" << RESET << std::endl;
    
    AMateria* ItemOnGround = NULL;
    
    warrior->unequip(1);

    std::cout << std::endl;
    std::cout << GREEN <<  "** Attempt to use Slot 1 (unequipped) **" << RESET << std::endl;
    ICharacter* target = new Character("Target");
    warrior->use(1, *target);

    std::cout << GREEN <<  "\n** Final cleanup **" << RESET << std::endl;
    delete target;
    delete warrior;
    delete src2;
    delete ItemOnGround;

    return 0;
}