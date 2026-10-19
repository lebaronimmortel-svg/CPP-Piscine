/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Convert.cpp"

std::string parse(const std::string& word)
{
    if (word == "+inf" || word == "-inf" || word == "+inff" || word == "-inff" || word == "nan" || word == "nanf")
        return ("special");
    if (n_dot(word) > 1 || n_char(word) > 1)
        return ("error");
    else if (!n_dot(word) && !n_digit(word) && n_char(word))
        return ("char");
    else if (n_dot(word) && n_digit(word) && !n_char(word))
        return ("double");
    else if (n_digit(word))
    {
        if (is_e_single_between(word) || is_last_char_f(word))
            return ("float");
        else if (!n_dot(word) && !n_char(word))
            return ("int");
    }
    return ("error");
}