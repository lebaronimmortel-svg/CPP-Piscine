#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		
		std::string name;
		Weapon* 	weapon;

	public:
		
					HumanB(const std::string n);
					~HumanB();
		void		attack() const;
		std::string	Get_name() const;
		void		Set_name(const std::string str);
		void		setWeapon(Weapon& to_set);
};

#endif