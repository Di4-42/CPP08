#include "Span.hpp"

Span::Span()
{
    std::cout << "Span default constructor called" << std::endl;    
}

Span::Span(unsigned int n)
{
    std::cout << "Span parameter constructor called" << std::endl;
}

Span::Span(const Span& source)
{
    std::cout << "Span copy constructor called" << std::endl;
}
}

Span& Span::operator=(const Span& source)
{
    std::cout << "Span assignment operator called" << std::endl;
    if (this != &source)
    {
        
    }
}

Span::~Span()
{
    std::cout << "Span destructor called" << std::endl;
}

unsigned int Span::shortestSpan() const
{

}

unsigned int Span::longestSpan() const
{

}
