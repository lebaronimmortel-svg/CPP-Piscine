#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Harl
{
    private:
        typedef void (Harl::*Action)();

        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);

    public:
                Harl();
                ~Harl();
        void    complain(std::string level);
};

#endif