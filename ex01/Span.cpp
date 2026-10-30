#include "Span.hpp"

// -----canonical form------

Span::Span() : _maxSize(0)
{
    std::cout << "Span default constructor called" << std::endl;    
}

Span::Span(unsigned int n) : _maxSize(n)
{
    std::cout << "Span parameter constructor called" << std::endl;
}

Span::Span(const Span& source) : _maxSize(source._maxSize), _numbers(source._numbers) 
{
    std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(const Span& source)
{
    std::cout << "Span assignment operator called" << std::endl;
    if (this != &source)
    {
        _numbers = source._numbers;
        _maxSize = source._maxSize;   
    }
    return (*this);
}

Span::~Span()
{
    std::cout << "Span destructor called" << std::endl;
}
//----fonction add----

void    Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is full");

    _numbers.push_back(number);
    
}

void    Span::addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
    std::size_t count = end - begin;

    if (count > _maxSize - _numbers.size())
        throw std::runtime_error("Span is full");
    
    _numbers.insert(_numbers.end(), begin, end);
}

//------Span min - max---------
unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("not enough numbers");
    
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());  //plus petit au plus grand

    unsigned int min = std::numeric_limits<unsigned int>::max();  //min commence à 4 294 967 295

    for (size_t i = 1; i < tmp.size(); i++)
    {
         long diff = static_cast<long>(tmp[i]) - static_cast<long>(tmp[i - 1]);

        if (diff > std::numeric_limits<unsigned int>::max())
            throw std::runtime_error("Span too large");
        
        unsigned int gap = static_cast<unsigned int>(diff);

        if (gap < min)
            min = gap;
    }
    return min;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("not enough numbers");

    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());

    long min = static_cast<long>(tmp[0]);
    long max = static_cast<long>(tmp[tmp.size() - 1]);
    long diff = std::abs(max - min);    //dernier − premier donne toujours le plus grand écart 

    if (diff > std::numeric_limits<unsigned int>::max())
            throw std::runtime_error("Span too large");

    unsigned int gap = static_cast<unsigned int>(diff);

    return gap;
}
