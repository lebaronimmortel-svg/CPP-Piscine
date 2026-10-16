#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::map <std::string, float> input) : _input(input) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : _input(copy._input) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
    if (this != &rhs)
    {
        _input = rhs._input;
    }
    return (*this);
}

std::string trunc_line_csv(std::string& line, unsigned int flag)
{
    std::string result;
    if (flag == 0)
    {
        for (unsigned int i = 0; i < 10; i++)
            result += line[i];
    }
    else
    {
        for (unsigned int i = 11; i < line.size(); i++)
            result += line[i];
    }

    return (result);
}

static double rate(std::string date)
{
    std::string line;
    std::string csv ("data.csv");
    std::fstream data (csv.c_str());

    if (!data.is_open())
        return (-1);
    
    std::getline(data, line);
    std::string old_line = line;
    while (std::getline(data, line))
    {
        std::string trunc = trunc_line_csv(line, 0);
        if (trunc == date)
            return (atof(trunc_line_csv(line, 1).c_str()));
        else if (trunc > date)
            return (atof(trunc_line_csv(old_line, 1).c_str()));
        old_line = line;
    }
    
    return (atof(trunc_line_csv(old_line, 1).c_str()));
}

void BitcoinExchange::CalcValue()
{
    std::map<std::string, float>::iterator it = _input.begin();
     
    while (it != _input.end())
    {
        double res = rate(it->first);
        if (res == -1)
            throw std::runtime_error("Error : unable to open database file !");
        std::cout << BOLD BLUE << "Date : " << RESET << it->first << ", " << BOLD BLUE << "Value : " << RESET << it->second << " * " << res << " = " << GREEN << it->second * res << RESET << std::endl;
        it++;
    }
}
