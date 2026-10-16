/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:39:16 by alexfuen          #+#    #+#             */
/*   Updated: 2026/05/19 13:39:18 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include <cstdlib>
# include "PhoneBook.hpp"
# include "Contact.hpp"

std::string truncate(std::string str);
int	is_space(std::string str);
void display_contact(Contact contact);

#endif
