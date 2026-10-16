#include "iter.hpp"

int main()
{
    std::cout << std::endl << BLUE << BOLD << "[Instantiating a new integer array of size 5]" << RESET << std::endl;

    int* array = new int [5];

    std::cout << std::endl << BLUE << BOLD << "[Filling array with index values]" << RESET << std::endl;

    for (int i = 0; i < 5; i++)
        array[i] = i;

    std::cout << std::endl << BLUE << BOLD << "[Calling iter on array with function member 'print values']" << RESET << std::endl << std::endl;    

    iter(array, 5, print);

    std::cout << std::endl << BLUE << BOLD << "[Instantiating a new char array of size 5]" << RESET << std::endl;

    char* str = new char [5];

    std::cout << std::endl << BLUE << BOLD << "[Filling array with alphabetical values]" << RESET << std::endl;

    for (char c = 'a'; c < 'f'; c++)
        str[c - 'a'] = c;

    std::cout << std::endl << BLUE << BOLD << "[Calling iter on array with function member 'print values']" << RESET << std::endl << std::endl;    

    iter(str, 5, print);

    std::cout << std::endl;
    
    delete [] str;
    delete [] array;
}
