/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RESET   "\033[0m"      
#define GREEN   "\033[32m"          
#define BLUE    "\033[34m"          
#define BOLD    "\033[1m"

#include <iostream>
#include <stack>
#include <algorithm>

class RPN
{
    private :

        std::stack<int> _stack;
        std::string _sequence;

    public :

        RPN();
        ~RPN();
        RPN(char *inp);
        RPN(const RPN& copy);
        RPN& operator=(const RPN& rhs);

        void calc();
        long operate(char c, long left, long right);
};