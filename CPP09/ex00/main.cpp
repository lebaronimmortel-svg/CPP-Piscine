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

#include "BitcoinExchange.hpp"

static unsigned int number_of_dots(std::string& line)
{
    unsigned int cpt = 0;
    
    for (unsigned int i = 0; i < line.size(); i++)
    {
        if (line[i] == '.')
            cpt++;
    }

    return (cpt);
}

static int is_valid_date(std::string& line)
{
    int year = std::atoi(&line[0]);
    int month = std::atoi(&line[5]);
    int day = std::atoi(&line[8]);

    if (month == 2 && day > 28)
    {
        if (year % 4 == 0 && day == 29)
            return (1);
        return (0);
    }

    if ((month % 2 == 0 && month < 8) || (month % 2 == 1 && month > 8))
    {
        if (day > 30)
            return (0);
        return (1);
    }

    return (1);
}

static unsigned int parse_line_inp(std::string& line)
{
    if (line.size() < 14)
        return (1);

    for (unsigned int i = 0; i < 10; i++)
    {
        if (!isdigit(line[i]))
        {
            if (!(line[i] == '-' && (i == 4 || i == 7)))
                return (1);
        }
        if ((i == 5 && std::atoi(&line[i]) > 12) || (i == 8 && std::atoi(&line[i]) > 31))
            return (3);
    }

    if (number_of_dots(line) > 1)
        return (1);

    for (unsigned int i = 10; i < 13; i++)
    {
        if (i == 11 && line[i] != '|')
            return (5);
        if ((i == 10 || i == 12) && line[i] != ' ')
            return (5);
    }

    for (unsigned int i = 13; i < line.size(); i++)
    {
        if (i == 13 && (std::atoi(&line[i]) < 0 || std::atoi(&line[i]) > 1000))
            return (4);

        if (!isdigit(line[i]))
        {
            if (line[i] != '.')
                return (2);
        }
    }

    if (!is_valid_date(line))
        return (3);

    return (0);
}

static std::string trunc_line_inp(std::string& line, unsigned int flag)
{
    std::string result;

    if (flag == 0)
    {
        for (unsigned int i = 0; i < 10; i++)
            result += line[i];
    }

    else
    {
        for (unsigned int i = 13; i < line.size(); i++)
            result += line[i];
    }

    return (result);
}

static std::string status_msg(int flag)
{
    switch(flag)
    {
        case 1 : 
            return " Invalid date format";

        case 2 : 
            return " Invalid value format";

        case 3 :
            return " Invalid date";

        case 4 :
            return " Invalid value";

        default :
            return " Invalid syntax";
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error : file name required" << std::endl;
        return (-1);
    }

    std::string inp (argv[1]);
    std::fstream inp_s (inp.c_str());

    if (!inp_s.is_open())
    {
        std::cerr << "Error : unable to open input file" << std::endl;     
        return (-1);
    }

    std::cout << std::endl;
    std::string line;
    std::map <std::string, float> input;

    while (std::getline(inp_s, line))
    {
        int flag = parse_line_inp(line);
        if (!flag)
          input[trunc_line_inp(line, 0)] = atof(trunc_line_inp(line, 1).c_str());
        else if (line.size() > 0)
            std::cerr << BOLD BLUE << "Error: " << RESET << line << GREEN << status_msg(flag) << RESET << std::endl;
    }

    BitcoinExchange instance(input);
    try
    {
        instance.CalcValue();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
}
