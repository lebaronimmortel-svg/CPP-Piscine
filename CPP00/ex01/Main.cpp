/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

int main(void)
{
    std::string str;
    std::string str2;
    PhoneBook phonebook;
    phonebook.init();    
    
    while (1)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, str))
            break;
        if (str == "ADD")
            phonebook.SetContact();
        else if (str == "SEARCH")
        {
            phonebook.display_all();
            if (phonebook.has_contacts() == 0)
                std::cout << "No contacts\n";
            else
            {
                std::cout << "Enter an index : ";
                if (!std::getline(std::cin, str2))
                    break;
                phonebook.search_contact(str2);
            }
        }
        else if (str == "EXIT")
            break;
        else
        	std::cout << "Unknown command\n";
    }
    return (0);
}
