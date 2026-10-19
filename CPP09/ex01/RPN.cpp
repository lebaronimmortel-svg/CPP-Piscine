/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 21:12:45 by alexfuen          #+#    #+#             */
/*   Updated: 2026/10/19 21:12:45 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    for (unsigned long i = 0; i < _sequence.size(); i++)
    {
        if (_sequence[i] == ' ')
            continue;

        if (isdigit(_sequence[i]))
        {
            if (i + 1 < _sequence.size() && _sequence[i + 1] != ' ')
                throw std::runtime_error("Error: Number must be less than 10");
            _stack.push(_sequence[i] - '0');
        }
        else if (_sequence[i] == '+' || _sequence[i] == '-' || 
                 _sequence[i] == '*' || _sequence[i] == '/')
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error: Missing operand");

            long right = _stack.top();
            _stack.pop();
            long left = _stack.top();
            _stack.pop();

            long res = this->operate(_sequence[i], left, right);

            if (res > 2147483647 || res < -2147483648)
                throw std::runtime_error("Error: Value out of integer range");

            _stack.push(static_cast<int>(res));
        }
        else
            throw std::runtime_error("Error: Invalid token");
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error: Invalid expression format");

    std::cout << BOLD GREEN << _stack.top() << RESET << std::endl;
}

