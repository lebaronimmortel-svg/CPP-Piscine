/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <iterator>
# include <climits>

class Span 
{
    private:

        unsigned int        _maxSize;
        std::vector<int>    _numbers;

    public:
    
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int number);
        
        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end)
        {
            if (std::distance(begin, end) + _numbers.size() > _maxSize)
                throw std::runtime_error("Unable to insert range : Max size reached !");
            _numbers.insert(_numbers.end(), begin, end);
        }

        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        class SizeOverflow : public std::exception
        {
            public :

                virtual const char* what() const throw()
                {
                    return "Unable to insert range : Max size reached !";
                }
        };

        class TooFew : public std::exception
        {
            public :

                virtual const char* what() const throw()
                {
                    return "Unable to calculate span : Too few numbers !";
                }
        };

        class FullSpan : public std::exception
        {
            public :

                virtual const char* what() const throw()
                {
                    return "Unable to insert number : Span is full !";
                }
        };
};
