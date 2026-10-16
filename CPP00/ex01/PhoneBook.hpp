/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:39:16 by alexfuen          #+#    #+#             */
/*   Updated: 2026/05/19 13:39:18 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Header.hpp"
#include "Contact.hpp"

class PhoneBook
{
	private:

    	Contact 	list[8];
    	int     	n;
    	int     	j;

	public:

		int			has_contacts();
    	void    	add_to_list(Contact contact);
    	void    	search_contact(std::string str);
    	void    	display_all();
		void		SetContact();
		void		init();
};

#endif