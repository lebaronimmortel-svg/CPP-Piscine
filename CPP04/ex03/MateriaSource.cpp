/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    _learntMaterias = new AMateria*[4];
    for (int i = 0; i < 4; i++)
    {
        _learntMaterias[i] = NULL;
    }
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_learntMaterias[i] != NULL)
            delete _learntMaterias[i];
    }
    delete [] _learntMaterias;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->_learntMaterias[i] == NULL)
        {
            this->_learntMaterias[i] = m;
            return;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_learntMaterias[i] != NULL && this->_learntMaterias[i]->getType() == type)
        {
            return this->_learntMaterias[i]->clone();
        }
    }
    return NULL; 
}

MateriaSource::MateriaSource(const MateriaSource& copy) : IMateriaSource(copy)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;

    this->_learntMaterias = new AMateria*[4];
    for (int i = 0; i < 4; i++)
    {
        this->_learntMaterias[i] = copy._learntMaterias[i];
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    std::cout << "MateriaSource operator= called" << std::endl;

    if (this != &rhs)
    {
        IMateriaSource::operator=(rhs);
        for (int i = 0; i < 4; i++)
        {
            this->_learntMaterias[i] = rhs._learntMaterias[i];
        }
    }
    return *this;
}
