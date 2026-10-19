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

void printTitle(const std::string& title)
{
    std::cout << BLUE << "\n========================================\n";
    std::cout << "  " << title << "\n";
    std::cout << "========================================\n" << RESET;
}

int main() 
{
    printTitle("TEST 1: Valid Bureaucrats and operator<<");
    try 
    {
        Bureaucrat hermes("Hermes Conrad", 3);
        Bureaucrat bob("Bob", 150);
        Bureaucrat chief("The Chief", 1);

        std::cout << hermes << std::endl;
        std::cout << bob << std::endl;
        std::cout << chief << std::endl;
    }
    catch (const std::exception& msg) 
    {
        std::cerr << GREEN << "Unexpected exception: " << msg.what() << RESET << std::endl;
    }
    printTitle("TEST 2: Instantiation with Grade Too High (0)");
    try
    {
        Bureaucrat Icarus("Icarus", 0);
        std::cout << "This line should not be executed." << std::endl;
    }
    catch (const std::exception& msg)
    {
        std::cerr << GREEN << "Caught expected exception: " << msg.what() << RESET << std::endl;
    }
    printTitle("TEST 3: Instantiation with Grade Too Low (151)");
    try 
    {
        Bureaucrat slacker("Slacker", 151);
        std::cout << "This line should not be executed." << std::endl;
    }
    catch (const std::exception& msg)
    {
        std::cerr << GREEN << "Caught expected exception: " << msg.what() << RESET << std::endl;
    }
    printTitle("TEST 4: Valid Increment / Decrement");
    try
    {
        Bureaucrat jean("Jean", 3);
        std::cout << "Initial: " << jean << std::endl;

        jean.incr_grade();
        std::cout << "After increment: " << jean << std::endl;

        jean.decr_grade();
        std::cout << "After decrement: " << jean << std::endl;
    }
    catch (const std::exception& msg)
    {
        std::cerr << GREEN << "Unexpected exception: " << msg.what() << RESET << std::endl;
    }
    printTitle("TEST 5: Incrementing past Grade 1");
    try
    {
        Bureaucrat elite("Elite Bureaucrat", 2);
        std::cout << elite << std::endl;
        
        elite.incr_grade();
        std::cout << elite << std::endl;

        std::cout << "Attempting to increment past 1..." << std::endl;
        elite.incr_grade();
        std::cout << "This line should not be executed." << std::endl;
    }
    catch (const std::exception& msg)
    {
        std::cerr << GREEN << "Caught expected exception: " << msg.what() << RESET << std::endl;
    }
    printTitle("TEST 6: Decrementing past Grade 150");
    try
    {
        Bureaucrat trainee("Trainee", 149);
        std::cout << trainee << std::endl;

        trainee.decr_grade();
        std::cout << trainee << std::endl;

        std::cout << "Attempting to decrement past 150..." << std::endl;
        trainee.decr_grade();
        std::cout << "This line should not be executed." << std::endl;
    }
    catch (const std::exception& msg)
    {
        std::cerr << GREEN << "Caught expected exception: " << msg.what() << RESET << std::endl;
    }
    printTitle("END OF EX00 TESTS");
    return 0;
}