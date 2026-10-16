#include <iostream>
#include <iomanip>
#include "ScalarConverter.hpp"

int main()
{
    std::cout << std::endl;

    std::cout << GREEN << "42 :" << RESET << std::endl;
    ScalarConverter::convert("42");
    std::cout << std::endl;

    std::cout << GREEN << "42.0 :" << RESET << std::endl;
    ScalarConverter::convert("42.0");
    std::cout << std::endl;

    std::cout << GREEN << "42.0f :" << RESET << std::endl;
    ScalarConverter::convert("42.0f");
    std::cout << std::endl;
    
    std::cout << GREEN << "42f :" << RESET << std::endl;
    ScalarConverter::convert("42f");
    std::cout << std::endl;

    std::cout << GREEN << "00.0 :" << RESET << std::endl;
    ScalarConverter::convert("00.0");
    std::cout << std::endl;

    std::cout << GREEN << "0.000 :" << RESET << std::endl;
    ScalarConverter::convert("0.000");
    std::cout << std::endl;

    std::cout << GREEN << "0.00026 :" << RESET << std::endl;
    ScalarConverter::convert("0.00026");
    std::cout << std::endl;

    std::cout << GREEN << "0.00000026 :" << RESET << std::endl;
    ScalarConverter::convert("0.00000026");
    std::cout << std::endl;

    std::cout << GREEN << "3e5 :" << RESET << std::endl;
    ScalarConverter::convert("3e5");
    std::cout << std::endl;

    std::cout << GREEN << "3e+5 :" << RESET << std::endl;
    ScalarConverter::convert("3e+5");
    std::cout << std::endl;

    std::cout << GREEN << "3e-5 :" << RESET << std::endl;
    ScalarConverter::convert("3e-5");
    std::cout << std::endl;

    std::cout << GREEN << "3e+5f :" << RESET << std::endl;
    ScalarConverter::convert("3e+5f");
    std::cout << std::endl;

    std::cout << GREEN << "3e-5f :" << RESET << std::endl;
    ScalarConverter::convert("3e-5f");
    std::cout << std::endl;

    std::cout << GREEN << "42.000012 :" << RESET << std::endl;
    ScalarConverter::convert("42.000012");
    std::cout << std::endl;

    std::cout << GREEN << "42.000012f :" << RESET << std::endl;
    ScalarConverter::convert("42.000012");
    std::cout << std::endl;

    std::cout << GREEN << "42.12 :" << RESET << std::endl;
    ScalarConverter::convert("42.12");
    std::cout << std::endl;

    std::cout << GREEN << "42.12f :" << RESET << std::endl;
    ScalarConverter::convert("42.12f");
    std::cout << std::endl;

    std::cout << GREEN << "42.541 :" << RESET << std::endl;
    ScalarConverter::convert("42.541");
    std::cout << std::endl;

    std::cout << GREEN << "w :" << RESET << std::endl;
    ScalarConverter::convert("w");
    std::cout << std::endl;

    std::cout << GREEN << "(space):" << RESET << std::endl;
    ScalarConverter::convert(" ");
    std::cout << std::endl;

    std::cout << GREEN << "2147483647:" << RESET << std::endl;
    ScalarConverter::convert("2147483647");
    std::cout << std::endl;

    std::cout << GREEN << "2147483648:" << RESET << std::endl;
    ScalarConverter::convert("2147483648");
    std::cout << std::endl;

    std::cout << GREEN << "999999.09" << RESET << std::endl;
    ScalarConverter::convert("999999.09");
    std::cout << std::endl;

    std::cout << GREEN << "1000000.09" << RESET << std::endl;
    ScalarConverter::convert("1000000.09");
    std::cout << std::endl; 

    std::cout << GREEN << "999999.09f" << RESET << std::endl;
    ScalarConverter::convert("999999.09");
    std::cout << std::endl;

    std::cout << GREEN << "1000000.09f" << RESET << std::endl;
    ScalarConverter::convert("1000000.09");
    std::cout << std::endl; 

    std::cout << GREEN << "1e5f" << RESET << std::endl;
    ScalarConverter::convert("1e5f");
    std::cout << std::endl;

    std::cout << GREEN << "1e-5f" << RESET << std::endl;
    ScalarConverter::convert("1e-5f");
    std::cout << std::endl;

    std::cout << GREEN << "1e30:" << RESET << std::endl;
    ScalarConverter::convert("1e30");
    std::cout << std::endl;

    std::cout << GREEN << "1e50:" << RESET << std::endl;
    ScalarConverter::convert("1e50");
    std::cout << std::endl;

    std::cout << GREEN << "+inf :" << RESET << std::endl;
    ScalarConverter::convert("+inf");
    std::cout << std::endl;

    std::cout << GREEN << "+inff :" << RESET << std::endl;
    ScalarConverter::convert("+inff");
    std::cout << std::endl;

    std::cout << GREEN << "+inf :" << RESET << std::endl;
    ScalarConverter::convert("+inf");
    std::cout << std::endl;

    std::cout << GREEN << "-inff :" << RESET << std::endl;
    ScalarConverter::convert("-inff");
    std::cout << std::endl;

    std::cout << GREEN << "+inf :" << RESET << std::endl;
    ScalarConverter::convert("+inf");
    std::cout << std::endl;

    std::cout << GREEN << "-inf :" << RESET << std::endl;
    ScalarConverter::convert("-inf");
    std::cout << std::endl;

    std::cout << GREEN << "nan :" << RESET << std::endl;
    ScalarConverter::convert("nan");
    std::cout << std::endl;

    std::cout << GREEN << "nanf :" << RESET << std::endl;
    ScalarConverter::convert("nanf");
    std::cout << std::endl;
}