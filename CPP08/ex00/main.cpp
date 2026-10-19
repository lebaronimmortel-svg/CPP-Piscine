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

#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    try 
    {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Found in vector : " << *it << std::endl;
        easyfind(vec, 99);
    }

    catch (const std::exception& e) 
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);

    try 
    {
        std::list<int>::iterator it = easyfind(lst, 2);
        std::cout << "Found in list : " << *it << std::endl;
    }

    catch (const std::exception& e) 
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }

    return 0;
}