#include "ScalarConverter.hpp"

unsigned int n_dot(const std::string& word)
{
    unsigned int i = 0;
    unsigned int cpt = 0;

    while (i < word.size())
    {
        if (word[i] == '.')
            cpt++;
        i++;
    }
    return (cpt);
}

unsigned int n_char(const std::string& word)
{
    unsigned int i = 0;
    unsigned int cpt = 0;

    while (i < word.size())
    {
        if (word[i] == 'e' && i != 0 && (isdigit(word[i + 1]) || word[i + 1] == '-' || word[i + 1] == '+'))
        {
            i++;
            continue ;
        }
        else if (!isdigit(word[i]) && word[i] != '.' && word[i] != '-' && word[i] != '+')
            cpt++;

        i++;
    }
    return (cpt);
}

unsigned int is_e_single_between(const std::string& word)
{
    unsigned int i = 0;
    unsigned int flag = 0;

    while (i < word.size())
    {
        if (word[i] == 'e')
        {
            if (i != 0 && (isdigit(word[i + 1]) || word[i + 1] == '-' || word[i + 1] == '+'))
                flag++; 
        }
        i++;
    }
    if (flag != 1)
        return (0);
    return (1);
}

unsigned int n_digit(const std::string& word)
{
    unsigned int i = 0;
    unsigned int cpt = 0;

    while (i < word.size())
    {
        if (isdigit(word[i]))
            cpt++;
        i++;
    }
    return (cpt);
}

unsigned int is_last_char_f(const std::string& word)
{
    unsigned int i = word.size() - 1;

    if (word[i] == 'f' || word[i] == 'F')
        return (1);
    return (0);
}

int number_of_digits_after_dot(std::string word)
{
    int cpt = 0;
    int i = 0;
    int flag = 0;

    while (word[i])
    {
        if (word[i] == '.')
        {
            flag = 1;
            break ;
        }
        i++;
    }
    if (flag == 0)
        return (0);
    while (word[i])
    {
        if (isdigit(word[i]))
            cpt++;
        i++;
    }
    return cpt;
} 

