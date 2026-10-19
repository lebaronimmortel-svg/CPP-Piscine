/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Unknown")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;    
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;  
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    std::cout << "ShrubberyCreationForm operator= called" << std::endl;  
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void createShrubberyFile(const std::string& target)
{
    std::string filename = target + "_shrubbery";

    std::ofstream outfile(filename.c_str());

    if (!outfile.is_open()) 
    {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }

    outfile << "     ccee88oo\n";
    outfile << "  C8O8O8Q8PoOb o8oo\n";
    outfile << " dOB69QO8PdUOpBcO8oo\n";
    outfile << "C88OoO889QNo8O8O8O8OO\n";
    outfile << "   C8O8OO8U8pP o8oo\n";
    outfile << "     ||||       ||\n";
    outfile << "     ||||       ||\n";

    outfile.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    this->checkExecution(executor);
    createShrubberyFile(_target);
}