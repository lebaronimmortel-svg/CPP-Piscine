/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Unknown"), _signed(0), _grade_sign(150), _grade_exec(150) 
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name) : _name(name), _signed(0), _grade_sign(150), _grade_exec(150) 
{
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const std::string& name, int grade_sign, int grade_exec) : _name(name), _signed(0), _grade_sign(grade_sign), _grade_exec(grade_exec) 
{
    std::cout << "Form constructor called" << std::endl;
    if (grade_sign > 150)
    {
        throw Form::GradeTooLowException();
    }
    else if (grade_sign <= 0)
    {
        throw Form::GradeTooHighException();
    }
    else if (grade_exec > 150)
    {
        throw Form::GradeTooLowException();
    }
    else if (grade_exec <= 0)
    {
        throw Form::GradeTooHighException();
    }
}

Form::Form(const Form& copy) : _name(copy._name), _signed(copy._signed), _grade_sign(copy._grade_sign), _grade_exec(copy._grade_exec)
{
    std::cout << "Form copy constructor called" << std::endl;   
}

Form& Form::operator=(const Form& rhs)  
{
    if (this != &rhs)
    {
        _signed = rhs._signed;
    }
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{  
    return (_name);
}

bool Form::getSigned() const
{
    return (_signed);
}

int Form::getGradeSign() const
{
    return (_grade_sign);
}

int Form::getGradeExec() const
{
    return (_grade_exec);
}

std::ostream& operator<<(std::ostream& os, const Form& rhs)
{
    os << rhs.getName() << ", form with sign grade " << rhs.getGradeSign() << " and exec grade " << rhs.getGradeExec();
    if (rhs.getSigned() == 1)
        os << ", is signed";
    else
        os << ", is not signed";
    return (os);
}

void Form::beSigned(const Bureaucrat& param)
{
    if (param.getGrade() <= _grade_sign) 
    {
        _signed = 1;
    }
    else
    {
        throw Form::GradeTooLowException();
    }

}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}