/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.cpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    (void) copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
    std::cout << "ScalarConverter operator= called" << std::endl;
    (void) rhs;
    return (*this);
}

void ScalarConverter::convert(const std::string& word)
{
    std::string type = parse(word);

    if (type == "error")
    {
        std::cout << "Error: unknown type" << std::endl;
        return ;
    }
    if (type == "float")
        convert_float(word);
    else if (type == "int")
        convert_int(word);
    else if (type == "double")
        convert_double(word);
    else if (type == "char")
        convert_char(word);
    else if (type == "special")
        convert_special(word);
}