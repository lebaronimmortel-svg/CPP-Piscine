/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:

        MutantStack() : std::stack<T> () {}
        ~MutantStack() {}
        MutantStack(const MutantStack& other) : std::stack<T> (other) {}
        
        MutantStack& operator=(const MutantStack& other)
        {
            if (this != &other)
                std::stack<T>::operator=(other);
            return *this;
        }

        typedef typename std::deque<T>::iterator               iterator;

        iterator               begin()       {return this->c.begin();}
        iterator               end()         {return this->c.end();}
};

#endif
