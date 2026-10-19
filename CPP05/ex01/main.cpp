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

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void printTitle(const std::string& title)
{
    std::cout << BLUE << "\n========================================\n";
    std::cout << "  " << title << "\n";
    std::cout << "========================================\n" << RESET;
}

int main() 
{
    printTitle("INIT: Bureaucrats Creation");
    Bureaucrat boss("The Boss", 1);
    Bureaucrat secretary("Secretary", 50);
    Bureaucrat intern("Intern", 150);

    std::cout << boss << std::endl;
    std::cout << secretary << std::endl;
    std::cout << intern << std::endl;

    printTitle("TEST 1: Valid Form Creation & operator<<");
    try
    {
        Form f1("Tax Audit Form", 45, 20);
        Form f2("Coffee Machine Request", 140, 150);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    }
    catch (const std::exception& msg)
    {
        std::cerr << GREEN << "Unexpected exception: " << msg.what() << RESET << std::endl;
    }
    printTitle("TEST 2: Form Instantiation with Grade Too High (0)");
    try
    {
        Form invalidForm("God Protocol", 0, 50);
        std::cout << "This line should not be executed." << std::endl;
    }
    catch (const std::exception& msg)
    {
        std::cerr << GREEN << "Caught expected exception: " << msg.what() << RESET << std::endl;
    }
    printTitle("TEST 3: Form Instantiation with Grade Too Low (151)");
    try
    {
        Form invalidForm("Trash Duty", 50, 151);
        std::cout << "This line should not be executed." << std::endl;
    }
    catch (const std::exception& msg)
    {
        std::cerr << GREEN << "Caught expected exception: " << msg.what() << RESET << std::endl;
    }
    printTitle("TEST 4: Bureaucrat signForm() - Success & Failures");
    try
    {
        Form standardContract("Standard Contract", 45, 45);
        std::cout << "Initial state:\n" << standardContract << std::endl;

        std::cout << "--- Intern tries to sign ---" << std::endl;
        intern.signForm(standardContract);
        std::cout << standardContract << std::endl;

        std::cout << "--- Secretary tries to sign ---" << std::endl;
        secretary.signForm(standardContract);
        std::cout << standardContract << std::endl;

        std::cout << "--- Boss tries to sign ---" << std::endl;
        boss.signForm(standardContract);
        std::cout << standardContract << std::endl;
    }
    catch (const std::exception& msg)
    {
        std::cerr << GREEN << "Unexpected exception in workflow: " << msg.what() << RESET << std::endl;
    }
    printTitle("TEST 5: Direct Form::beSigned() Exception Handling");
    {
        Form topSecret("Top Secret Document", 10, 5);
        try
        {
            topSecret.beSigned(secretary);
            std::cout << "This line should not be executed." << std::endl;
        }
        catch (const std::exception& msg)
        {
            std::cerr << GREEN << "Direct catch of Form exception: " << msg.what() << RESET << std::endl;
        }
    }
    printTitle("END OF EX01 TESTS");
    return 0;
}
