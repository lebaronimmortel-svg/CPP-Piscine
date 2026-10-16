#ifndef FORM_HPP
#define FORM_HPP

#include <stdexcept>
#include <iostream>
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"      
#define GREEN   "\033[32m"          
#define BLUE    "\033[34m"          
#define BOLD    "\033[1m"

class Bureaucrat;

class Form
{
    private :

        const std::string _name;
        bool _signed;
        const int _grade_sign;
        const int _grade_exec;

    public :

        Form();
        Form(const std::string& name);
        Form(const std::string& name, int grade_sign, int grade_exec);
        Form(const Form& copy);
        Form& operator= (const Form& rhs);
        ~Form();

        std::string getName() const;
        bool getSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        void beSigned(const Bureaucrat& param);

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

std::ostream& operator<<(std::ostream& os, const Form& rhs);

#endif



