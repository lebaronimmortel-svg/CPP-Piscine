/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    Zombie::announce(void) const
{
    std::cout << "\n" << Get_name();
    std::cout << ": BraiiiiiiinnnzzzZ...\n";
}

void    Zombie::Set_name(const std::string str)
{
    name = str;
}

std::string Zombie::Get_name(void) const
{
    return (name);
}

Zombie::Zombie(void) {}

Zombie::~Zombie(void)
{
    std::string str;

    str = name;
    if (str.empty())
        return ;
    std::cout << str << " destroyed\n";
}