#pragma once

#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span
{
    private:
        unsigned int        _maxSize;
        std::vector<int>    _numbers;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span& source);
        Span& operator=(const Span& source);
        ~Span();

        void    addNumber(int number);
        unsigned int     shortestSpan() const;
        unsigned int     longestSpan() const;
        void    addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
};