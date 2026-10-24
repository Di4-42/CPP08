#include "Easyfind.hpp"

int main()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(42);
    numbers.push_back(7);

    
    try
    {
		
        std::vector<int>::iterator it = easyfind(numbers, 42);
        std::cout << "Trouve : " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        easyfind(numbers, 99);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}