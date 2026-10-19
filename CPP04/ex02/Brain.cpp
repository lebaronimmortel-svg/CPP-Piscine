/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int i)
{
    return (_ideas[i]);
}

Brain& Brain::operator=(Brain& rhs)
{
    std::cout << "Brain operator= constructor called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
            _ideas[i] = rhs.getIdea(i);
    }

    return *this;
}

void Brain::setIdea(int i, std::string idea)
{
    _ideas[i] = idea;
}

Brain::Brain(Brain& copy)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        _ideas[i] = copy.getIdea(i);
    }
}