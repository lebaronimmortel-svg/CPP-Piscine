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

#include "Serializer.hpp"

void print_Data(Data* intern)
{
    if (!intern)
        return ;
    std::cout << BLUE << intern->name << ", aged " << intern->age << " : " << RESET << std::endl;

    for (int i = 0; i < 3; i++)
        std::cout << intern->competences[i] << std::endl;
    std::cout << BLUE << "has address " << intern << RESET << std::endl;
    std::cout << std::endl;
}

int main()
{
    std::cout << std::endl;
    Data Alice = {"Alice", 24, {"Data", "AI", "Cybersec"}};
    print_Data(&Alice);

    std::cout << BLUE << BOLD << "[Serializing, then deserializing Alice, then printing her again]" << RESET << std::endl << std::endl;

    print_Data(Serializer::deserialize(Serializer::serialize(&Alice)));
}