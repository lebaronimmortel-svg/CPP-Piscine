/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#define RESET   "\033[0m"      
#define GREEN   "\033[32m"          
#define BLUE    "\033[34m"          
#define BOLD    "\033[1m"

class BitcoinExchange
{
    private :

        std::map<std::string, float> _input;

    public :

        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(std::map <std::string, float> input);
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator= (const BitcoinExchange& rhs);

        void printData();
        void CalcValue();
};