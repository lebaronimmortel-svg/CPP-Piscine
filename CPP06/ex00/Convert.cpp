#include "Utils.cpp"

void convert_int(const std::string& word)
{
    int flag = 1;
    long n = std::strtol(word.c_str(), NULL, 10);

    if (n >= 0 && n <= 255)
    {
        std::cout << BLUE << "char: " << RESET;
        if (n < 35 || n > 126)
            std::cout << "Non displayable";
        else
            std::cout << "'" << static_cast<char>(n) << "'";
        std::cout << std::endl;
    }
    else
        std::cout << BLUE << "char: " << RESET << "impossible" << std::endl;

    std::cout << BLUE << "int: " << RESET;
    if (n > 2147483647)
        std::cout << "impossible";
    else if  (n < -2147483648)
        std::cout << "impossible";
    else
    {
        std::cout << n;
        flag = 0;
    }
    std::cout << std::endl;
    if (n < 1000000)
        std::cout << std::fixed << std::setprecision(1);
    else
        std::cout << std::scientific;
    if (flag == 1)
    {
        double x = std::strtod(word.c_str(), NULL);
        std::cout << BLUE << "float: " << RESET;
        std::cout << static_cast<float>(x) << "f" << std::endl;
        std::cout << BLUE << "double: " << RESET << x << std::endl;
    }
    else
    {
        std::cout << BLUE << "float: " << RESET << static_cast<float>(n) << "f" << std::endl;
        std::cout << BLUE << "double: " << RESET << static_cast<double>(n) << std::endl;       
    }
}

void convert_char(const std::string& word)
{
    std::cout << std::fixed << std::setprecision(1);
    std::cout << BLUE << "char: " << RESET <<  "'" << word[0] << "'" << std::endl;
    std::cout << BLUE << "int: " << RESET << static_cast<int>(word[0]) << std::endl;
    std::cout << BLUE << "float: " << RESET << static_cast<float>(word[0]) << "f" << std::endl;
    std::cout << BLUE << "double: " << RESET << static_cast<double>(word[0]) << std::endl;
}

void    convert_special(const std::string& word)
{
    std::cout << BLUE << "char: " << RESET << "impossible" << std::endl;
    std::cout << BLUE << "int: " << RESET << "impossible" << std::endl;
    if (word == "+inf" || word == "+inff")
    {
        std::cout << BLUE << "float: " << RESET << "+inff" << std::endl;
        std::cout << BLUE << "double: " << RESET << "+inf" << std::endl;
    }
    else if (word == "-inf" || word == "-inff")
    {
        std::cout << BLUE << "float: " << RESET << "-inff" << std::endl;
        std::cout << BLUE << "double: " << RESET << "-inf" << std::endl;
    }
    else if (word == "nan" || word == "nanf")
    {
        std::cout << BLUE << "float: " << RESET << "nanf" << std::endl;
        std::cout << BLUE << "double: " << RESET << "nan" << std::endl;
    }
}

void convert_double(const std::string& word)
{
    double d = std::strtod(word.c_str(), NULL);

    if (d >= 0 && d <= 255)
    {
        if (d < 32 || d > 126)
            std::cout << BLUE << "char: " << RESET << "Non displayable" << std::endl;
        else
            std::cout << BLUE << "char: " << RESET << "'" << static_cast<char>(d) << "'" << std::endl;
    }
    else
        std::cout << BLUE << "char: " << RESET << "impossible" << std::endl;
    std::cout << BLUE << "int: " << RESET;
    if (d > 2147483647)
        std::cout << "impossible";
    else if (d < -2147483648)
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(d);
    if (number_of_digits_after_dot(word) > 0 && number_of_digits_after_dot(word) <= 3 && d < 1000000)
        std::cout << std::fixed << std::setprecision(number_of_digits_after_dot(word));
    else
        std::cout << std::scientific;
    std::cout << std::endl << BLUE << "float: " << RESET;
    std::cout << static_cast<float>(d) << "f";
    std::cout << std::endl << BLUE << "double: " << RESET << d << std::endl;
}

void convert_float(const std::string& word)
{
    float f = std::strtof(word.c_str(), NULL);

    if (f >= 0 && f <= 255)
    {
        std::cout << BLUE << "char: " << RESET;
        if (f < 32 || f > 126)
            std::cout << "non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    }
    else
        std::cout << BLUE << "char: " << RESET << "impossible" << std::endl;
    std::cout << BLUE << "int: " << RESET;
    if (f <= 2147483647.0 && f >= -2147483648.0)
        std::cout << static_cast<int>(f) << std::endl;
    else
        std::cout << "impossible" << std::endl;
    if (number_of_digits_after_dot(word) <= 3 && number_of_digits_after_dot(word) > 0 && f < 1000000)
        std::cout << std::fixed << std::setprecision(number_of_digits_after_dot(word));
    else
        std::cout << std::scientific;
    std::cout << BLUE << "float: " << RESET;
    std::cout << f << "f" << std::endl;
    std::cout << BLUE << "double: " << RESET << static_cast<double>(f);
    std::cout << std::endl;
}