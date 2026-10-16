#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(char *input) : _sequence(input) {}

RPN::RPN(const RPN& copy) : _stack(copy._stack), _sequence(copy._sequence) {}

RPN& RPN::operator=(const RPN& rhs)
{
    if (this != &rhs)
    {
        _sequence = rhs._sequence;
        _stack = rhs._stack;
    }
    return (*this);
}

RPN::~RPN() {}

long RPN::operate(char c, long left, long right)
{
    long res;

    switch (c)
    {
        case '+' :
        {
            res = left + right;
            break ;
        }

        case '-' :
        {
            res = left - right;
            break ;
        }

        case '*' :
        {
            res = left * right;
            break ;
        }

        case '/' :
        {
            if (right == 0)
                throw(std::runtime_error("Division by zero !"));
            res = left / right;
            break ;
        }
    }

    return (res);
}

void RPN::calc()
{
    long res = 0;

    for (unsigned long i = 0; i < _sequence.size(); i++)
    {
        if (_sequence[i] == ' ')
            continue; 
        else if (isdigit(_sequence[i]))
            _stack.push(std::atoi(&_sequence[i]));
        else if ((_stack.empty() || _stack.size() == 1 ) && !isdigit(_sequence[i]))
            throw (std::runtime_error("Missing operand"));

        else
        {
            long left = 0;
            long right = 0;

            right = _stack.top();
            _stack.pop();

            if (!_stack.empty())
            {
                left = _stack.top();
                _stack.pop();
            }

            res = this->operate(_sequence[i], left, right);

            if (res > 2147483647 || res < -2147483648)
                throw(std::runtime_error("Value out of integer range"));

            _stack.push(static_cast<int>(res));
        }
    }
    
    if (_stack.size() != 1)
        throw (std::runtime_error("Missing operator"));
    
    std::cout << BOLD GREEN << res << RESET << std::endl;
}

