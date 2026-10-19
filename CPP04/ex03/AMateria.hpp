/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
    protected:

        std::string _type;
        AMateria(const AMateria& copy);
        AMateria& operator=(const AMateria& copy);
        AMateria();
    
    public:

        AMateria (std::string const & type);
        virtual ~AMateria   ();
        std::string const & getType () const;
        virtual AMateria* clone () const = 0;
        virtual void use (ICharacter& target);
};

#endif