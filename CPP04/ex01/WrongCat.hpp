#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "Brain.hpp"
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    private :

        Brain* _brain;

    public :

        WrongCat();
        WrongCat(const WrongCat& copy);
        WrongCat& operator=(const WrongCat& rhs);
        ~WrongCat();
        void makeSound() const;
        std::string getIdea(int i);
        void setIdea(int index, const std::string idea);
};

#endif