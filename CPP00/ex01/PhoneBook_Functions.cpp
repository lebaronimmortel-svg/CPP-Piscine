/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_Functions.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:39:31 by alexfuen          #+#    #+#             */
/*   Updated: 2026/05/19 13:39:33 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

void    PhoneBook::init()
{
    n = 0;
    j = 0;
}

void    PhoneBook::add_to_list(Contact contact)
{
    if (n < 8)
    {
        list[n] = contact;
        n += 1;
    }
    else
    {
        list[j % 8] = contact;
        j += 1;
    }
}

void PhoneBook::SetContact(void)
{
    Contact contact;
    std::string str;

    std::cout << "Enter first name : ";
    std::getline(std::cin, str);
    if (str.empty() || is_space(str)) return;
    contact.SetString(str, 0);

    std::cout << "Enter last name : ";
    std::getline(std::cin, str);
    if (str.empty() || is_space(str)) return;
    contact.SetString(str, 1);

    std::cout << "Enter nickname : ";
    std::getline(std::cin, str);
    if (str.empty() || is_space(str)) return;
    contact.SetString(str, 2);

    std::cout << "Enter phone number : ";
    std::getline(std::cin, str);
    if (str.empty() || is_space(str)) return;
    contact.SetString(str, 3);

    std::cout << "Enter darkest secret : ";
    std::getline(std::cin, str);
    if (str.empty() || is_space(str)) return;
    contact.SetString(str, 4);

    add_to_list(contact);
}

int PhoneBook::has_contacts(void)
{
    if (n == 0 && j == 0)
        return (0);
    return (1);
}

void PhoneBook::display_all()
{
    int i = 0;
    int limit = (j > 0) ? 8 : n; 
    
    while (i < limit)
    {
        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << truncate(list[i].GetString(0)) << "|";
        std::cout << std::setw(10) << truncate(list[i].GetString(1)) << "|";
        std::cout << std::setw(10) << truncate(list[i].GetString(2)) << "\n";
        i++;
    }
}

void PhoneBook::search_contact(std::string str)
{   
    if (str.empty() || str.find_first_not_of("0123456789") != std::string::npos)
    {
        std::cout << "Invalid index\n";
        return;
    }

    int index = std::atoi(str.c_str()) - 1;
    int limit = (j > 0) ? 8 : n;

    if (index < 0 || index >= limit)
    {
        std::cout << "Unknown contact\n";
        return;
    }
    
    display_contact(list[index]);
}
