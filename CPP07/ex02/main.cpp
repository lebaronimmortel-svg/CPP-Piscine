#include "Array.hpp"

int main()
{
    std::cout << std::endl;

    std::cout << BLUE << BOLD << "[Out of bounds access : Instantiating an array(1) by default construction]" << RESET << std::endl;

    Array<int> myArray;

    std::cout << BLUE << "[Filling array with index values]" << RESET << std::endl;

    for (unsigned int i = 0; i < myArray.size(); i++)
    {
        myArray[i] = i;
    }

    std::cout << BLUE << "[Trying to access value at index 2]" << RESET << std::endl;
    
    try
    {
        std::cout << "Content of array at index 2 : " << std::endl << myArray[2] << std::endl;

    }
    catch (const std::exception& msg)
    {
        std::cerr << GREEN << msg.what() << RESET << std::endl;
    }

    std::cout << std::endl;

    std::cout << BLUE << BOLD << "[Instantiating an array(2) by specifying size 5]" << RESET << std::endl;

    Array<int> myArray2(5);

    std::cout << BLUE << "[Filling array with index values]" << RESET << std::endl;

    for (unsigned int i = 0; i < myArray2.size(); i++)
    {
        myArray2[i] = i;
    }

    std::cout << BLUE << "[Accessing value at index 2]" << RESET << std::endl;

    std::cout << "Content of array at index 2 : " << std::endl << myArray2[2] << std::endl;

    std::cout << std::endl;

    std::cout << BLUE << BOLD << "[Deep copy : Instantiating an array(3) by copying array(2)]" << RESET << std::endl;

    Array<int> myArray3 = Array<int>(myArray2);

    std::cout << BLUE << "[Accessing value at index 2]" << RESET << std::endl;

    std::cout << "Content of array at index 2 : " << std::endl << myArray3[2] << std::endl;
 
    std::cout << BLUE << "[Modifying this array by reversing values order]" << RESET << std::endl;

    for (unsigned int i = 0; i < myArray3.size(); i++)
    {
        myArray3[i] = myArray3.size() - i - 1;
    }

    std::cout << BLUE << "[Accessing values at index 0 and 4]" << RESET << std::endl;

    std::cout << "Content of original array(2) at index 0 : " << std::endl << myArray2[0] << std::endl;

    std::cout << "Content of original array(2) at index 4 : " << std::endl << myArray2[4] << std::endl;

    std::cout << "Content of copy array(3) at index 0 : " << std::endl << myArray3[0] << std::endl;

    std::cout << "Content of copy array(3) at index 4 : " << std::endl << myArray3[4] << std::endl;

    std::cout << std::endl;

    std::cout << BLUE << BOLD << "[Deep affectation : Assigning array(2) to array(3)]" << RESET << std::endl; 

    myArray3 = myArray2;

    std::cout << BLUE << "[Accessing array(3)'s value at index 0]" << RESET << std::endl;

    std::cout << "Content of array at index 0 : " << std::endl << myArray3[0] << std::endl;

    std::cout << BLUE << "[Assigning value '8' at array(3)'s index 0]" << RESET << std::endl;

    myArray3[0] = 8;

    std::cout << BLUE << "[Accessing array(3)'s value at index 0]" << RESET << std::endl;

    std::cout << "Content of array at index 0 : " << std::endl << myArray3[0] << std::endl;

    std::cout << BLUE << "[Accessing array(2)'s value at index 0]" << RESET << std::endl;

    std::cout << "Content of array at index 0 : " << std::endl << myArray2[0] << std::endl;

    std::cout << std::endl;

    std::cout << BLUE << BOLD << "[Const instance accessing : Instantiating a new const array(4) of size 5]" << RESET << std::endl; 

    const Array<int> myArray4(5);

    std::cout << BLUE << "[Accessing array(4)'s value at index 2]" << RESET << std::endl;

    std::cout << "Content of array at index 2 : " << std::endl << myArray4[2] << std::endl;

    std::cout << std::endl;

    std::cout << BLUE << BOLD << "[Genericality : Instantiating a new array(5) of an other type of size 5]" << RESET << std::endl; 

    Array<char> myArray5(5);

    std::cout << BLUE << "[Filling array with alphabetical values]" << RESET << std::endl;

    for (char c = 'a'; c < 'f'; c++)
    {
        myArray5[c - 'a'] = c;
    }

    std::cout << BLUE << "[Accessing array(5)'s value at index 2]" << RESET << std::endl;

    std::cout << "Content of array at index 2 : " << std::endl << myArray5[2] << std::endl;

    std::cout << std::endl;
}
