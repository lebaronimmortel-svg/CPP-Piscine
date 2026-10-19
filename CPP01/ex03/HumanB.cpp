/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack(void) const
{
	std::cout << name;
	std::cout << " attacks with their ";
	if (!weapon)
		std::cout << "hands" << std::endl;
	else
		std::cout << weapon->getType() << std::endl;
}

HumanB::HumanB(const std::string n) : weapon(NULL)
{
	Set_name(n);
}

HumanB::~HumanB(void) {}

void	HumanB::setWeapon(Weapon& to_set)
{
	weapon = &to_set;
}

std::string	HumanB::Get_name(void) const
{
	return (name);
}

void	HumanB::Set_name(const std::string str)
{
	name = str;
}