#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        std::cerr << BOLD BLUE << "Error :\n" << RESET << "Not enough parameters" << std::endl;
        return (-1);
    }

    vector_sort(argv);
    deque_sort(argv);

    return (0);
}