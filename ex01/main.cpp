#include "Span.hpp"

int main()
{
    std::cout << "\n--- Exemple du sujet ---" << std::endl;
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest : " << sp.shortestSpan()
                  << " (attendu 2)" << std::endl;
        std::cout << "Longest : " << sp.longestSpan()
                  << " (attendu 14)" << std::endl;

        try
        {
            sp.addNumber(42);
        }
        catch (const std::exception& e)
        {
            std::cout << "Span plein : " << e.what() << std::endl;
        }
    }

    std::cout << "\n--- Zero puis un nombre ---" << std::endl;
    {
        Span sp(2);

        for (int i = 0; i < 2; i++)
        {
            std::cout << "Nombre d'elements : " << i << std::endl;

            try
            {
                sp.shortestSpan();
            }
            catch (const std::exception& e)
            {
                std::cout << "Shortest : " << e.what() << std::endl;
            }

            try
            {
                sp.longestSpan();
            }
            catch (const std::exception& e)
            {
                std::cout << "Longest : " << e.what() << std::endl;
            }

            if (i == 0)
                sp.addNumber(42);
        }
    }

    std::cout << "\n--- Constructeur par defaut ---" << std::endl;
    {
        Span sp;

        try
        {
            sp.addNumber(1);
        }
        catch (const std::exception& e)
        {
            std::cout << "Capacite zero : " << e.what() << std::endl;
        }
    }

    std::cout << "\n--- Negatifs et doublons ---" << std::endl;
    {
        Span sp(4);

        sp.addNumber(-10);
        sp.addNumber(-3);
        sp.addNumber(-3);
        sp.addNumber(5);

        std::cout << "Shortest : " << sp.shortestSpan()
                  << " (attendu 0)" << std::endl;
        std::cout << "Longest : " << sp.longestSpan()
                  << " (attendu 15)" << std::endl;
    }

    std::cout << "\n--- Copie et affectation ---" << std::endl;
    {
        Span original(3);
        original.addNumber(10);
        original.addNumber(20);

        Span copie(original);
        Span affectation;
        affectation = original;

        original.addNumber(100);
        copie.addNumber(15);
        affectation.addNumber(12);

        std::cout << "Original : " << original.shortestSpan()
                  << " (attendu 10)" << std::endl;
        std::cout << "Copie : " << copie.shortestSpan()
                  << " (attendu 5)" << std::endl;
        std::cout << "Affectation : " << affectation.shortestSpan()
                  << " (attendu 2)" << std::endl;
    }

    std::cout << "\n--- 10000 nombres par iterateurs ---" << std::endl;
    {
        std::vector<int> numbers;

        for (int i = 0; i < 10000; i++)
            numbers.push_back(i);

        Span sp(10000);
        sp.addNumber(numbers.begin(), numbers.end());

        std::cout << "Shortest : " << sp.shortestSpan()
                  << " (attendu 1)" << std::endl;
        std::cout << "Longest : " << sp.longestSpan()
                  << " (attendu 9999)" << std::endl;
    }

    std::cout << "\n--- Plage trop grande ---" << std::endl;
    {
        std::vector<int> numbers;
        numbers.push_back(10);
        numbers.push_back(20);
        numbers.push_back(30);

        Span sp(2);

        try
        {
            sp.addNumber(numbers.begin(), numbers.end());
        }
        catch (const std::exception& e)
        {
            std::cout << "Depassement : " << e.what() << std::endl;
        }
    }

    return 0;
}