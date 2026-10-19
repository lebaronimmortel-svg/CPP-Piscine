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

#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define RESET   "\033[0m"     
#define GREEN   "\033[32m"         
#define BLUE    "\033[34m"           
#define BOLD    "\033[1m"

int main()
{
    std::cout << BLUE << BOLD << "\n=== TEST 0 : ORTHODOX FORM (ANIMAL) ===" << RESET << std::endl;

    std::cout << std::endl;
    std::cout << GREEN << "** Creating a static Animal aw **" << RESET << std::endl; 
    Animal aw;

    std::cout << std::endl;
    std::cout << GREEN << "** Creating a static Animal by copying aw **" << RESET << std::endl; 
    Animal ax(aw);

    std::cout << std::endl;
    std::cout << GREEN << "** Creating a static Animal az then overloading it from aw **" << RESET << std::endl;  
    Animal az;
    az = aw;

    std::cout << std::endl;
    std::cout << GREEN << "** Making all three make sound **" << RESET << std::endl;
    std::cout << "aw : ";
    aw.makeSound();
    std::cout << "ax : ";
    ax.makeSound();
    std::cout << "az : ";
    az.makeSound();

    std::cout << std::endl;
    std::cout << GREEN << "** Making all three print their types **" << RESET << std::endl;

    std::cout << "aw type : "  << aw.getType() << std::endl;
    std::cout << "ax type : "  << ax.getType() << std::endl;
    std::cout << "az type : "  << az.getType() << std::endl;

    std::cout << BLUE << BOLD "\n=== TEST 1 : ORTHODOX FORM (CAT) ===" << RESET << std::endl;

    std::cout << std::endl;
    std::cout << GREEN << "** Creating a static Cat w **" << RESET << std::endl; 
    Cat w;

    std::cout << std::endl;
    std::cout << GREEN << "** Creating a static Cat x by copying w **" << RESET << std::endl; 
    Cat x(w);

    std::cout << std::endl;
    std::cout << GREEN << "** Creating a static Cat z then overloading it from w **" << RESET << std::endl;  
    Cat z;
    z = w;

    std::cout << std::endl;
    std::cout << GREEN << "** Making all three make sound **" << RESET << std::endl;
    w.makeSound();
    x.makeSound();
    z.makeSound();

    std::cout << BLUE << BOLD << "\n=== TEST 2 : COPY DEPTH ===" << RESET << std::endl;

    std::cout << std::endl;
    std::cout << GREEN << "** Creating a new Dog origin **" << RESET << std::endl; 
    Dog* origin = new Dog();

    std::cout << std::endl;
    std::cout << GREEN << "** Setting first idea as 'Eat' **" << RESET << std::endl; 
    origin->setIdea(0, "Eat");

    std::cout << std::endl;
    std::cout << GREEN << "** Creating a new Dog by copying origin **" << RESET << std::endl;
    Dog* copy = new Dog(*origin);

    std::cout << std::endl;
    std::cout << "Origin idea [0] : " << origin->getIdea(0) << std::endl;
    std::cout << "Copy idea [0] : " << copy->getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << GREEN << "** Modifying origin's first idea as 'Play' **" << RESET << std::endl;
    origin->setIdea(0, "Play");

    std::cout << std::endl;
    std::cout << "Origin idea [0] : " << origin->getIdea(0) << std::endl;
    std::cout << "Copy idea [0] : " << copy->getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << GREEN << "** Creating a new WrongCat origin2 **" << RESET << std::endl; 
    WrongCat* origin2 = new WrongCat();

    std::cout << std::endl;
    std::cout << GREEN << "** Setting first idea as 'Eat' **" << RESET << std::endl;
    origin2->setIdea(0, "Eat");

    std::cout << std::endl;
    std::cout << GREEN << "** Creating a new WrongCat by copying origin2 **" << RESET << std::endl;
    WrongCat* copy2 = new WrongCat(*origin2);

    std::cout << std::endl;
    std::cout << "Origin2 idea [0] : " << origin2->getIdea(0) << std::endl;
    std::cout << "Copy2 idea [0] : " << copy2->getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << GREEN << "** Modifying origin2's first idea as 'Play' **" << RESET << std::endl;
    origin2->setIdea(0, "Play");

    std::cout << std::endl;
    std::cout << "Origin2 idea [0] : " << origin2->getIdea(0) << std::endl;
    std::cout << "Copy2 idea [0] : " << copy2->getIdea(0) << std::endl;

    std::cout << std::endl << GREEN << "** Dynamic instances destruction **" << RESET << std::endl;
    delete origin;
    delete copy;
    delete origin2;

    std::cout << BLUE << BOLD << "\n=== TEST 4 : ARRAY ===" << RESET << std::endl;

    std::cout << std::endl;
    std::cout << GREEN << "** Creating an array of 4 Dogs and 4 Cats **" << RESET << std::endl;

    Animal *array[8];

    for (int i = 0; i < 8; i++)
    {
        if (i < 4)
            array[i] = new Cat();
        else
            array[i] = new Dog();
    }
    
    std::cout << std::endl;
    std::cout << GREEN << "** Deleting the array **" << RESET << std::endl;

    for (int i = 0; i < 8; i++)
    {
        delete array[i];
        array[i] = NULL;
    }

    std::cout << std::endl << GREEN << "** Static instances destruction **" << RESET << std::endl;

    return 0;
}

