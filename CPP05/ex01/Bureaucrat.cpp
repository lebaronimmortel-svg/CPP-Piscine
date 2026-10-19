/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else if (grade <= 0)
    {
        throw Bureaucrat::GradeTooHighException();
    }
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade (150)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("Unknown"), _grade (grade)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else if (grade <= 0)
    {
        throw Bureaucrat::GradeTooHighException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs)
    {
        _grade = rhs._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs)
{
    os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return (os);
}

int Bureaucrat::getGrade() const 
{
    return _grade;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

void Bureaucrat::decr_grade()
{ 
    if (_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade = _grade + 1;
}

void Bureaucrat::incr_grade()
{ 
    if (_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    else
        _grade = _grade - 1;
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;  
    }
    catch (const std::exception& msg)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << msg.what() << std::endl;
    }        
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}