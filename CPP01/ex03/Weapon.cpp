#include "Weapon.hpp"

const std::string &Weapon::getType(void) const
{
    return (type);
}

void		Weapon::setType(const std::string str)
{
    type = str;
}

Weapon::Weapon(const std::string str)
{
	type = str;
}

Weapon::~Weapon(void){}