#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) 
{
    _numbers.reserve(N);
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other) 
{
    if (this != &other) 
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int number) 
{
    if (_numbers.size() >= _maxSize)
        throw Span::FullSpan();
    _numbers.push_back(number);
}

unsigned int Span::longestSpan() const 
{
    if (_numbers.size() <= 1)
        throw Span::TooFew();

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<unsigned int>(maxVal - minVal);
}

unsigned int Span::shortestSpan() const 
{
    if (_numbers.size() <= 1)
        throw Span::TooFew();

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = UINT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        unsigned int span = static_cast <unsigned int>(sorted[i] - sorted[i - 1]);
        if (span < minSpan)
            minSpan = span;
    }
    return (minSpan);
}
