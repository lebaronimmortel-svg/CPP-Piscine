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

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int main() 
{
	std::srand(std::time(NULL));

    std::cout << BOLD << BLUE << "\n========================================\n";
    std::cout << " Basic Form Signing" << std::endl;
    std::cout << "\n=======================================\n" << RESET;
    std::cout << std::endl << std::endl;
    Bureaucrat *Jean = new Bureaucrat("Jean", 25);
    Bureaucrat *Damien = new Bureaucrat("Damien", 4);
    std::cout << *Jean << std::endl;
    std::cout << *Damien << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << std::endl << std::endl;
    AForm *Form = new PresidentialPardonForm("Yoshi");
    std::cout << std::endl << std::endl;
    std::cout << *Form << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << "Form grade to be signed : " << Form->getGradeSign() << std::endl;
    std::cout << "Jean's grade : " << Jean->getGrade() << std::endl;
    std::cout << "Retrograding Jean" << std::endl;
    Jean->decr_grade();
    std::cout << "Jean's grade : " << Jean->getGrade() << std::endl;
    std::cout << std::endl << std::endl; 
    Jean->signForm(*Form);
    Jean->executeForm(*Form);
    std::cout << *Form << std::endl << std::endl;
    Damien->signForm(*Form);
    Damien->executeForm(*Form);
    std::cout << std::endl << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    delete Jean;
    delete Damien;
    delete Form;
    std::cout << std::endl << std::endl;

    std::cout << BOLD << BLUE << "\n========================================\n";
    std::cout << " Creation of an enterprise " << std::endl;
    std::cout << "\n=======================================\n" << RESET;

    std::cout << std::endl << std::endl;

    Bureaucrat boss("The Boss", 1);
    Bureaucrat manager("Manager", 45);
    Bureaucrat intern("Intern", 150);

    std::cout << std::endl << std::endl;

    std::cout << boss << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << manager << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << intern << std::endl;

    std::cout << std::endl << std::endl;
    std::cout << BOLD << BLUE << "\n========================================\n";
    std::cout << " ShrubberyCreation " << std::endl;
    std::cout << "\n=======================================\n" << RESET;
    std::cout << std::endl << std::endl;
    {
        AForm* shrub = new ShrubberyCreationForm("garden");

        std::cout << *shrub << std::endl;
        std::cout << std::endl << std::endl;   
        intern.executeForm(*shrub);

        intern.signForm(*shrub);
        std::cout << std::endl << std::endl;
        manager.signForm(*shrub);
        std::cout << *shrub << std::endl;
        std::cout << std::endl << std::endl;
        intern.executeForm(*shrub);

        manager.executeForm(*shrub);
        std::cout << std::endl << std::endl;
        delete shrub;
    }

    std::cout << std::endl << std::endl;
    std::cout << BOLD << BLUE << "\n========================================\n";
    std::cout << " Robotomy" << std::endl;
    std::cout << "\n=======================================\n" << RESET;
    std::cout << std::endl << std::endl;
    {
        AForm* robotomy = new RobotomyRequestForm("Jeff");

        manager.executeForm(*robotomy);

        manager.signForm(*robotomy);
    
        std::cout << std::endl << std::endl;
        std::cout << "--- Testing 50% randomness (Executing 3 times) ---" << std::endl;
        std::cout << std::endl << std::endl;
        manager.executeForm(*robotomy);
        std::cout << std::endl << std::endl;
        boss.executeForm(*robotomy);
        std::cout << std::endl << std::endl;
        boss.executeForm(*robotomy);
        std::cout << std::endl << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;

        delete robotomy;
    }

    std::cout << std::endl << std::endl;
    std::cout << BOLD << BLUE << "\n========================================\n";
    std::cout << " Presidential Pardon " << std::endl;
    std::cout << "\n=======================================\n" << RESET;
    std::cout << std::endl << std::endl;
    {
        AForm* pardon = new PresidentialPardonForm("Zorro");

        manager.signForm(*pardon);
        std::cout << std::endl << std::endl;
        boss.signForm(*pardon);
        std::cout << std::endl << std::endl;
        manager.executeForm(*pardon);
        std::cout << std::endl << std::endl;
        boss.executeForm(*pardon);
        std::cout << std::endl << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;

        delete pardon;
    }

    std::cout << std::endl << std::endl;
    std::cout << BOLD << BLUE << "\n========================================\n";
    std::cout << " Direct Exception Catching " << std::endl;
    std::cout << "\n=======================================\n" << RESET;
    std::cout << std::endl << std::endl;
    {
        PresidentialPardonForm secretForm("Criminal");
        Bureaucrat lowRank("LowRank", 30);

        boss.signForm(secretForm);

        try
        {
            secretForm.execute(lowRank);
        }
        catch (const std::exception& msg)
        {
            std::cerr << msg.what() << std::endl;
        }
    }
    std::cout << std::endl << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
}
