/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool is_valid_char(char c)
{
    if (isdigit(c) || c == ' ')
        return (true);
        
    if (c == '+' || c == '/' || c == '*' || c == '-')
        return (true);

    return (false);
}

static bool parse_inp(char *inp)
{
    if (!inp)
        return (false);
  
    std::string seq = "";
    int i = 0;

    while (inp[i])
        seq += inp[i++];

    for (unsigned long j = 0; j < seq.size(); j++)
    {
        if (!is_valid_char(seq[j]))
        {
            std::cerr << BOLD BLUE << "Error :\n" << RESET << "Invalid character" << std::endl;
            return (false);
        }
    
        if (std::atoi(&seq[j]) < 0 || std::atoi(&seq[j]) > 9)
        {
            std::cerr << BOLD BLUE << "Error :\n" << RESET << "Invalid value" << std::endl;
            return (false);
        }
    }

    return (true);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << BOLD BLUE << "Error :\n" << RESET << "Invalid args count" << std::endl;    
        return (-1);
    }
    
    if (!parse_inp(argv[1]))
        return (-1);

    RPN instance(argv[1]);

    try
    {
        instance.calc();
    }
    catch (std::exception &e)
    {
        std::cerr << BOLD BLUE << "Error :\n" << RESET << e.what() << std::endl;
        return (-1);
    }

    return (0);
}