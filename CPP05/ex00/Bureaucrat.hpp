#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define RESET   "\033[0m"      
#define GREEN   "\033[32m"          
#define BLUE    "\033[34m"          
#define BOLD    "\033[1m"

#include <stdexcept>
#include <iostream>

class Bureaucrat
{	
	private :
	
		const std::string _name;
		int _grade;
	
	public :

		Bureaucrat();
		Bureaucrat(const std::string& name);
		Bureaucrat(int grade);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator= (const Bureaucrat& rhs);
		~Bureaucrat();

		void incr_grade();
		void decr_grade();
		std::string getName() const;
		int getGrade() const;

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
