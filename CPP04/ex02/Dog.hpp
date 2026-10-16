#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    private :

        Brain* _brain;

    public :

        Dog();
        Dog(const Dog& copy);
        Dog& operator=(const Dog& rhs);
        ~Dog();
        void makeSound() const;
        std::string getIdea(int i);
        void setIdea(int index, std::string idea);
};

#endif