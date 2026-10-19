/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
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

#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <deque>
#include "sys/time.h"

int power(int src, int pow);
void vector_sort(char **argv);
void deque_sort(char **argv);

template <typename T>
struct split
{
    T winners;
    T losers;
};

template <typename T>
class PmergeMe
{
    private :

        T       _seq;
        long    _start;

    public :

        PmergeMe() {};
        
        ~PmergeMe() {};

        PmergeMe(const PmergeMe& copy) : _seq(copy._seq), _start(copy._start) {};
        
        PmergeMe& operator=(const PmergeMe& rhs)
        {
            if (this != &rhs)
            {
                _seq = rhs._seq;
                _start = rhs._start;
            }
            return (*this);
        };

        void setStart(long time)
        {
            _start = time;
        }

        long getStart()
        {
            return _start;
        }

        T getSeq()
        {
            return _seq;
        }

        void fill(char **args)
        {
            if (!args)
                return ;

            int i = 1;
            while (args[i])
            {
                int len = 0;
                while (args[i][len])
                    len++;

                for (int j = 0; j < len; j++)
                {
                    if (!isdigit(args[i][j]) && !(args[i][j] == '-' && (j == 0 || args[i][j - 1] == ' ') && isdigit(args[i][j + 1])))
                        throw (std::runtime_error("Invalid character"));
                }

                long n = std::atol(args[i++]);
                if (len > 20 || n > 2147483647 || n < -2147483648)
                    throw(std::runtime_error("Invalid value"));
                
                _seq.push_back(n);
            }
        }

        void insertDich(T* win, int n)
        {
            if (win->empty())
            {
                win->push_back(n);
                return;
            }

            int left = 0;
            int right = static_cast<int>(win->size()) - 1;

            while (left <= right)
            {
                int mid = left + (right - left) / 2;

                if ((*win)[mid] < n)
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            win->insert(win->begin() + left, n);
        }

        void print(T win)
        {
            int i = 0;
            for (typename T::iterator it = win.begin(); it != win.end(); it++)
            {
                if (i > 5)
                {
                    std::cout << "[...]" << std::endl;
                    return ;
                }
                std::cout << *it << " ";
                i++;
            }
            std::cout << std::endl;
        }

        void insert(split<T>* in)
        {
            int i = 1;
            int previous = 0;
            size_t cnt = 0;

            while (cnt < in->losers.size())
            {
                int jac = (power(2, i) - power(-1, i)) / 3;
                int tmp = jac;
                if (jac > static_cast<int>(in->losers.size()))
                    jac = static_cast<int>(in->losers.size());
                while (jac > previous)
                {
                    insertDich(&((*in).winners), (*in).losers.at(jac - 1));
                    cnt++;
                    jac--;
                }
                previous = tmp;
                i++;
            } 
        }

        struct split<T> sort(split<T> in)
        {
            if (in.winners.size() < 2)
                return (in);
            
            split<T> res = markPair(in.winners);
            split<T> res2 = sort(res);

            res2.losers = res.losers;
            insert(&res2);

            return (res2);
        }
        
        struct split<T> markPair(T seq)
        {
            struct split<T> res;

            typename T::iterator it = seq.begin();
            typename T::iterator ite = seq.end();
            size_t i = 0;

            while (it != ite)
            {
                if (i % 2 != 0)
                {
                    if (*it > *(it - 1))
                    {
                        res.winners.push_back(*it);
                        res.losers.push_back(*(it - 1));
                    }
                    else
                    {
                        res.losers.push_back(*it);
                        res.winners.push_back(*(it - 1));                       
                    }
                }
                else if (i == seq.size() - 1)
                    res.losers.push_back(*it);

                it++;
                i++;
            }

            return (res);
        }
};