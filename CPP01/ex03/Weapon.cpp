/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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