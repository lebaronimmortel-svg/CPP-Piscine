/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:39:16 by alexfuen          #+#    #+#             */
/*   Updated: 2026/05/19 13:39:18 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "Header.hpp"
#include "PhoneBook.hpp"

class Contact 
{
	private :

    	std::string first_name;
    	std::string last_name;
    	std::string nickname;
    	std::string phone_number;
    	std::string darkest_secret;

	public :

		void		SetString(std::string str, int field);
		std::string GetString(int field);
};

#endif
