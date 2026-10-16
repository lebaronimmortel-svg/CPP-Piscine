#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

#define RESET   "\033[0m"      
#define GREEN   "\033[32m"          
#define BLUE    "\033[34m"          
#define BOLD    "\033[1m"

class ScalarConverter
{
    private :

        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& rhs);

    public :

        static void convert(const std::string& word);
};

void convert_int(const std::string& word);
void convert_char(const std::string& word);
void convert_special(const std::string& word);
void convert_double(const std::string& word);
void convert_float(const std::string& word);

#endif