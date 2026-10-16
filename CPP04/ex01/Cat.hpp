#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    private :

        Brain* _brain;

    public :

        Cat();
        Cat(const Cat& copy);
        Cat& operator=(const Cat& rhs);
        ~Cat();
        void makeSound() const;                 
        std::string getIdea(int i);
        void setIdea(int index, const std::string idea);
};

#endif