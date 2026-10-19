/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>

#define RESET   "\033[0m"      
#define GREEN   "\033[32m"          
#define BLUE    "\033[34m"          
#define BOLD    "\033[1m"

struct Data
{
    std::string name;
    unsigned int age;
    std::string competences[3];
};

class Serializer
{
    private :

        Serializer();
        ~Serializer();
        Serializer(const Serializer& copy);
        Serializer& operator=(const Serializer& rhs);

    public :

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

