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
    std::cout << GREEN << "** Creating a static Animal ax by copying aw **" << RESET << std::endl; 
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

    std::cout << BLUE << BOLD << "\n=== TEST 1 : ORTHODOX FORM (CAT) ===" << RESET << std::endl;

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

    std::cout << BLUE << BOLD << "\n=== TEST 2 : VIRTUALITY ===" << RESET << std::endl;

    std::cout << std::endl;
    std::cout << GREEN << "** Creating a new Animal **" << RESET << std::endl;
    const Animal* meta = new Animal();

    std::cout << std::endl;
    std::cout << GREEN << "** Creating a new Dog **" << RESET << std::endl;
    const Animal* j = new Dog();

    std::cout << std::endl;
    std::cout << GREEN << "** Creating a new Cat **" << RESET << std::endl;
    const Animal* i = new Cat();

    std::cout << std::endl;
    std::cout << GREEN << "** Creating a new WrongCat **" << RESET << std::endl;
    const WrongAnimal* k = new WrongCat();

    std::cout << std::endl;
    std::cout << GREEN << "** Making Dog make sound **" << RESET << std::endl;
    j->makeSound();

    std::cout << std::endl;
    std::cout << GREEN << "** Making Cat make sound **" << RESET << std::endl;
    i->makeSound();

    std::cout << std::endl;
    std::cout << GREEN << "** Making Animal make sound **" << RESET << std::endl;
    meta->makeSound();

    std::cout << std::endl;
    std::cout << GREEN << "** Making WrongCat make sound **" << RESET << std::endl;
    k->makeSound();

    std::cout << std::endl;
    std::cout << GREEN << "** Destroying allocated Dog, Cat, and Animal **" << RESET << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << std::endl;
    std::cout << GREEN << "** Static instances destruction **" << RESET << std::endl;
    return 0;
}