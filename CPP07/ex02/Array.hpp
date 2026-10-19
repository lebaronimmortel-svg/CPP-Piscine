/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

#define RESET   "\033[0m"      
#define GREEN   "\033[32m"          
#define BLUE    "\033[34m"          
#define BOLD    "\033[1m"

template <typename T> class Array 
{
    private:

        T* _data;
        unsigned int _size;

    public:

        Array () : _data(NULL), _size (0)
        {
            std::cout << "Array default constructor called" << std::endl;
        }

        Array (unsigned int n) : _data(new T [n]), _size(n)
        {
            for (unsigned int i = 0; i < n; i++)
                _data[i] = 0;
            std::cout << "Array constructor called" << std::endl;
        }

        Array(const Array& copy) : _size(copy._size)
        {
            std::cout << "Array copy constructor called" << std::endl;
            _data = new T [copy.size()];
            for (unsigned int i = 0; i < copy.size(); i++)
                _data[i] = copy._data[i];
        }

        ~Array()
        {
            std::cout << "Array destructor called" << std::endl;
            delete [] _data;
        }

        Array& operator=(const Array& rhs)
        {
            std::cout << "Array operator= called" << std::endl;

            if (this != &rhs)
            {
                _size = rhs.size();
                delete [] _data;
                _data = new T [rhs.size()];
                for (unsigned int i = 0; i < rhs.size(); i++)
                    _data[i] = rhs._data[i];
            }
            return *this;
        }

        T& operator[](unsigned int i)
        {
            std::cout << "Array operator[] called" << std::endl;

            if (i >= size())
                throw Array::OutOfBoundsException();
            return (_data[i]);
        }

        const T& operator[](unsigned int i) const
        {
            std::cout << "Array operator[] called" << std::endl;

            if (i >= size())
                throw Array::OutOfBoundsException();
            return (_data[i]);
        }

        unsigned int size() const
        {
            return (_size);
        }

        class OutOfBoundsException : public std::exception
        {
            public :

                virtual const char* what() const throw()
                {
                    return "Index is out of bounds!";
                }
        };
};

#endif