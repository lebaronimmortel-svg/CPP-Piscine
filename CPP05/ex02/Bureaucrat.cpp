#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
    else if (grade == 0)
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
    std::cout << "Bureaucrat operator= called" << std::endl;
    if (this != &rhs)
    {
        _grade = rhs._grade;
    }
    return *this;
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

const std::string Bureaucrat::getName() const
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

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        if (_grade <= form.getGradeSign())
        {
            form.beSigned(*this);
            std::cout << _name << " signed " << form.getName() << std::endl; 
        }
        else
            throw Bureaucrat::GradeTooLowException();
    }
    catch (const std::exception& msg)
    {
        std::cerr << GREEN << _name << " couldn't sign " << form.getName() << " : " << msg.what() << RESET << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try 
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << GREEN << _name << " couldn't execute " << form.getName() 
                  << " because: " << e.what() << RESET << std::endl;
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