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

#include "Zombie.hpp"

int main(void)
{
    Zombie      *stack[200] = {};
    int         nb_zombies;
    std::string str;

    nb_zombies = 0;

    std::cout << "Enter 1 to create a random chump whose lifetime is limited\n";
    std::cout << "Enter 2 to create a real independant zombie\n";
    std::cout << "Enter 3 to clean up the mess and exit the program\n";

    while (1)
    {
        if (nb_zombies == 200)
            break ;

        std::cout << "\nEnter a command (1, 2, 3) : ";
        std::getline(std::cin, str);

        if (str == "1")
        {
            Zombie zombie;
            std::cout << "Name the random chump : ";
            std::getline(std::cin, str);
            if (!str.empty())
                randomChump(str);
        }

        else if (str == "2")
        {
            std::cout << "Name the new zombie : ";
            std::getline(std::cin, str);
            stack[nb_zombies] = newZombie(str);
            nb_zombies += 1;
        }

        else if (str == "3")
            break ;
        
        else if (str.empty())
        {
            std::cout << "\n";
            break ;
        }

        else
            std::cout << "Unknown command\n";
    }

    std::cout << "\nCleaning up this mess...\n";
    int i = 0;
    while (i < nb_zombies)
    {
        delete stack[i];
        stack[i] = NULL;
        i++;
    }

    return (0);
}
