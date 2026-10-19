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

#include "Span.hpp"

int main()
{
    std::cout << "--- Subject test ---" << std::endl;
    try 
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Doit afficher 2
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;  // Doit afficher 14
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Massive test (20 000 nombres) ---" << std::endl;
    try 
    {
        Span bigSpan(20000);
        std::vector<int> randomNums(20000);
        std::srand(std::time(NULL));
        
        for (size_t i = 0; i < randomNums.size(); ++i) 
        {
            randomNums[i] = std::rand();
        }

        bigSpan.addNumbers(randomNums.begin(), randomNums.end());

        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << bigSpan.longestSpan() << std::endl;
    }
    catch (const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Exceptions test ---" << std::endl;
    try 
    {
        Span fullSpan(2);
        fullSpan.addNumber(10);
        fullSpan.addNumber(20);
        fullSpan.addNumber(30);
    }
    catch (const std::exception &e) 
    {
        std::cout << "Captured Exception : " << e.what() << std::endl;
    }

    return 0;
}
