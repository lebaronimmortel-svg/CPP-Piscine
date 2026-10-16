#include "Zombie.hpp"

int main(void)
{
	std::string name;
	std::string number;
	int 		n;

	std::cout << "Give zombies a name : ";
	std::getline(std::cin, name);
	if (name.empty())
	{
		std::cout << "Invalid name\n";
		return (0);
	}

	std::cout << "Give zombies a number : ";
	std::getline(std::cin, number);

	n = std::atoi(number.c_str());

	if (n <= 0)
    {
        std::cout << "Invalid number of zombies\n";
        return (0);
    }

	Zombie *horde = zombieHorde(n , name);

	std::cout << "\n";
	delete[] horde;
	
	return (0);
}
