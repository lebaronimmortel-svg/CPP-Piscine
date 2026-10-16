/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_Functions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:39:31 by alexfuen          #+#    #+#             */
/*   Updated: 2026/05/19 13:39:33 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

std::string truncate(std::string str)
{
    if (str.length() > 10)
    {
        str[9] = '.';
        str.resize(10);
    }
    return (str);
}

int	is_space(std::string str)
{
	int i;
	int flag;
	
	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] > 33)
			flag = 1;
        i++;
	}
    if (flag)
        return (0);
    else
        return (1);
}

void display_contact(Contact contact)
{
    std::cout << "First Name: " << contact.GetString(0) << "\n";
    std::cout << "Last Name: " << contact.GetString(1) << "\n";
    std::cout << "Nickname: " << contact.GetString(2) << "\n";
    std::cout << "Phone Number: " << contact.GetString(3) << "\n";
    std::cout << "Darkest Secret: " << contact.GetString(4) << "\n";
}