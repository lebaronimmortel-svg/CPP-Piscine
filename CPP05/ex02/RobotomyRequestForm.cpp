#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Unknown")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;    
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy), _target(copy._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;  
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    std::cout << "RobotomyRequestForm operator= called" << std::endl;  
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void    perform_robotomy(std::string _target)
{
    int rand = std::rand() % 2;
    
    std::cout << "DRRRRRRRRRRRRRR" << std::endl;

    if (rand == 0)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else   
        std::cout << "Robotomy of " << _target << " failed" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    this->checkExecution(executor);
    perform_robotomy(_target);
}