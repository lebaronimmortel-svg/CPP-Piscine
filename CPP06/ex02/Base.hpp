#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>

#define RESET   "\033[0m"      
#define GREEN   "\033[32m"          
#define BLUE    "\033[34m"          
#define BOLD    "\033[1m"

class Base
{
    public :
        virtual ~Base();
};

#endif