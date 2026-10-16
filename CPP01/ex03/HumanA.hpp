#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		
		std::string name;
		Weapon 		&weapon;

	public:
		
					HumanA(const std::string n, Weapon &w);
					~HumanA();
		void		attack() const;
		std::string	Get_name() const;
		void		Set_name(const std::string str);
		void		setWeapon(Weapon &to_set);
};

#endif
