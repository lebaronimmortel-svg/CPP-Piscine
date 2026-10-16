#include "Dog.hpp"
#include "Cat.hpp"

#define RESET   "\033[0m"      
#define GREEN   "\033[32m"         
#define BLUE    "\033[34m"          
#define BOLD    "\033[1m"

int main() 
{
    std::cout << BLUE << BOLD << "\n=== TEST 0 : INSTANTIABILITY (ANIMAL) ===" << RESET << std::endl << std::endl;

    /*
    Animal  StaticAnimal; 
    Animal* DynamicAnimal = new Animal();
    */

    Dog* myDog = new Dog();
    Cat* myCat = new Cat();
    Animal* myAnimal = new Dog();

    delete myDog;
    delete myCat;
    delete myAnimal;

    return 0;
} 