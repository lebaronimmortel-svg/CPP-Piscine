#include "HumanA.hpp"

HumanA::HumanA(const std::string n, Weapon &w)
				: name(n), weapon(w)
				{}

HumanA::~HumanA() {}

void	HumanA::attack(void) const
{
	std::cout << name;
	std::cout << " attacks with their ";
	std::cout << weapon.getType();
	std::cout << std::endl;
}

std::string HumanA::Get_name(void) const
{
	return (name);
}

void	HumanA::Set_name(const std::string str)
{
	name = str;
}

void	HumanA::setWeapon(Weapon &to_set)
{
	weapon = to_set;
}
