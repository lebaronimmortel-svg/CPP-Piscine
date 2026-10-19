/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Unknown"), _signed(0), _grade_sign(150), _grade_exec(150) 
{
    std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(std::string name) : _name(name), _signed(0), _grade_sign(150), _grade_exec(150) 
{
    std::cout << "Form constructor called" << std::endl;
}

AForm::AForm(std::string name, int grade_sign, int grade_exec) : _name(name), _signed(0), _grade_sign(grade_sign), _grade_exec(grade_exec) 
{
    std::cout << "Form constructor called" << std::endl;
    if (grade_sign > 150)
    {
        throw AForm::GradeTooLowException();
    }
    else if (grade_sign <= 0)
    {
        throw AForm::GradeTooHighException();
    }
    else if (grade_exec > 150)
    {
        throw AForm::GradeTooLowException();
    }
    else if (grade_exec <= 0)
    {
        throw AForm::GradeTooHighException();
    }
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signed(copy._signed), _grade_sign(copy._grade_sign), _grade_exec(copy._grade_exec)  
{
    std::cout << "Form copy constructor called" << std::endl;
}

AForm& AForm::operator= (const AForm& rhs)
{
    if (this != &rhs)
    {
        std::cout << "Form operator= constructor called" << std::endl;
        _signed = rhs._signed;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string AForm::getName() const
{  
    return (_name);
}

bool AForm::getSigned() const
{
    return (_signed);
}

int AForm::getGradeSign() const
{
    return (_grade_sign);
}

int AForm::getGradeExec() const
{
    return (_grade_exec);
}

std::ostream& operator<<(std::ostream& os, const AForm& rhs)
{
    os << rhs.getName() << ", form with sign grade " << rhs.getGradeSign() << " and exec grade " << rhs.getGradeExec();
    if (rhs.getSigned() == 1)
        os << ", is signed";
    else
        os << ", is not signed";
    return (os);
}

unsigned int AForm::beSigned(Bureaucrat& param)
{
    if (param.getGrade() <= _grade_sign) 
    {
        _signed = 1;
        return (1);
    }
    else
    {
        throw GradeTooLowException();
        return (0);
    }
}

void AForm::checkExecution(Bureaucrat const & executor) const 
{
    if (!_signed)
        throw AForm::UnsignedFormException();
    if (executor.getGrade() > _grade_exec)
        throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* AForm::UnsignedFormException::what() const throw()
{
    return "Unsigned form!";
}