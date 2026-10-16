#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    private :
    
        std::string _ideas[100];

    public :

        Brain();
        Brain(Brain& copy);
        Brain& operator=(Brain& rhs);
        ~Brain();
        std::string getIdea(int i);
        void setIdea(int index, std::string idea);
};

#endif