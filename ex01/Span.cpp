#include "Span.hpp"

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

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("not enough numbers");
    
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());  //plus petit au plus grand

    unsigned int min = static_cast<unsigned int>(tmp[1]) - static_cast<unsigned int>(tmp[0]);   //3, 10, 42


    for (size_t i = 2; i < tmp.size(); i++)
    {
        unsigned int diff = static_cast<unsigned int>(tmp[i]) - static_cast<unsigned int>(tmp[i - 1]);   //L’écart maximal vaut 4 294 967 295
                                                                                                        //tient dans un unsigned int mais pas dans int

        if (diff < min)
            min = diff;
    }
    return min;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("not enough numbers");

    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());

    unsigned int min = static_cast<unsigned int>(tmp[0]);
    unsigned int max = static_cast<unsigned int>(tmp[tmp.size() - 1]);
    unsigned int diff = max - min;    //dernier − premier donne toujours le plus grand écart 

    return diff;
}
