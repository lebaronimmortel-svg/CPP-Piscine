/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_Functions.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

void    Contact::SetString(std::string str, int field)
{
    if (field == 0)
        first_name = str;
    else if (field == 1)
        last_name = str;
    else if (field == 2)
        nickname = str;
    else if (field == 3)
        phone_number = str;
    else if (field == 4)
        darkest_secret = str;
}

std::string Contact::GetString(int field)
{
    std::string result;

    if (field == 0)
        result = first_name;
    else if (field == 1)
        result = last_name;
    else if (field == 2)
        result = nickname;
    else if (field == 3)
        result = phone_number;
    else if (field == 4)
        result = darkest_secret;
    else
        result = "";
    return (result);
}
