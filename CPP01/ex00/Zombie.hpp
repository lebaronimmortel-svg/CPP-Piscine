#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    private:

        std::string name;

    public:

        void        announce() const;
        void        Set_name(const std::string str);
        std::string Get_name() const;
                    Zombie();
                    ~Zombie();
};

void    randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif