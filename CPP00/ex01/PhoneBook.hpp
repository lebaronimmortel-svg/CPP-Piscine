/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
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