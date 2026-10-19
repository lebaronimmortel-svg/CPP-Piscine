/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{	
	private :
	
		const std::string _name;
		int _grade;
	
	public :

		Bureaucrat();
		Bureaucrat(const std::string name);
		Bureaucrat(int grade);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();

		void incr_grade();
		void decr_grade();
		const std::string getName() const;
		int getGrade() const;
		void signForm(AForm& param);
		void executeForm(AForm const & form) const;

		class GradeTooLowException : public std::exception
		{
			public:

				virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:

				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif
