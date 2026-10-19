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

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    // test 01 : subject main
    
    std::cout << std::endl << "=== Test 01 ===" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << "Stack elements from bottom to top :" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // test 02 

    std::cout << std::endl << "=== Test 02 ===" << std::endl;

    MutantStack<int> mstack1;
    mstack1.push(59);
    mstack1.push(6);
    mstack1.push(34);
    mstack1.push(23);
    mstack1.push(-895);
    std::cout << "Top element: " << mstack1.top() << std::endl;
    mstack1.pop();
    std::cout << "Size after pop: " << mstack1.size() << std::endl;
    mstack1.push(24);
    mstack1.push(-17);
    mstack1.push(12);
    mstack1.push(-64);
    mstack1.push(3);
    mstack1.push(0);
    MutantStack<int>::iterator it1 = mstack1.begin();
    MutantStack<int>::iterator ite1 = mstack1.end();

    ++it1;
    --it1;

    std::cout << "Stack elements from bottom to top :" << std::endl;
    while (it1 != ite1)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }
    std::cout << std::endl;


    std::cout << std::endl << "=== Test 03 (MStack becomes List) ===" << std::endl;

    std::list<int> list1;
    list1.push_back(59);
    list1.push_back(6);
    list1.push_back(34);
    list1.push_back(23);
    list1.push_back(-895);
    std::cout << "Top element: " << list1.back() << std::endl;
    list1.pop_back();
    std::cout << "Size after pop: " << list1.size() << std::endl;
    list1.push_back(24);
    list1.push_back(-17);
    list1.push_back(12);
    list1.push_back(-64);
    list1.push_back(3);
    list1.push_back(0);
    std::list<int>::iterator it2 = list1.begin();
    std::list<int>::iterator ite2 = list1.end();

    ++it2;
    --it2;

    std::cout << "Stack elements from bottom to top :" << std::endl;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    std::cout << std::endl;
}

