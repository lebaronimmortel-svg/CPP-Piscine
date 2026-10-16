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

class AForm
{
    private :

        const std::string _name;
        bool _signed;
        const int _grade_sign;
        const int _grade_exec;

    public :

        AForm();
        AForm(std::string name);
        AForm(std::string name, int grade_sign, int grade_exec);
        AForm(const AForm& copy);
        AForm& operator= (const AForm& rhs);
        virtual ~AForm();
        
        std::string getName() const;
        bool getSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        unsigned int beSigned(Bureaucrat& param);
        virtual void execute(Bureaucrat const & executor) const = 0;
        void checkExecution(Bureaucrat const & executor) const;

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

        class UnsignedFormException : public std::exception
		{
			public:

				virtual const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif



