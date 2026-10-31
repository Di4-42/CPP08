#include "MutantStack.hpp"

int main()
{
    MutantStack<int> pile;

    std::cout << "--- Pile vide ---" << std::endl;
    std::cout << pile.empty() << std::endl; // return 1 si pile est vide

    std::cout << "--- Push, top, pop, size ---" << std::endl;
    pile.push(10);
    pile.push(20);
    pile.push(30);
    std::cout << pile.top() << std::endl; // 30

    pile.pop();
    std::cout << pile.top() << std::endl;  // 20
    std::cout << pile.size() << std::endl; // 2

    std::cout << "--- Iterateurs ---" << std::endl;
    MutantStack<int>::iterator it = pile.begin();
    ++it;
    std::cout << *it << std::endl; // 20
    --it;

    while (it != pile.end())
    {
        std::cout << *it << std::endl; // 10 puis 20
        ++it;
    }

    std::cout << "--- Comparaison list ---" << std::endl;
    std::list<int> liste;
    liste.push_back(10);
    liste.push_back(20);

    std::list<int>::iterator i = liste.begin();
    while (i != liste.end())
    {
        std::cout << *i << std::endl; // 10 puis 20
        ++i;
    }

    std::cout << "--- Copie et modification ---" << std::endl;
    MutantStack<int> copie(pile);
    *copie.begin() = 99;
    std::cout << *copie.begin() << std::endl; // 99
    std::cout << *pile.begin() << std::endl;  // 10

    std::cout << "--- Affectation ---" << std::endl;
    MutantStack<int> autre;
    autre.push(42);
    autre = pile;
    autre.pop();
    std::cout << autre.top() << std::endl; // 10
    std::cout << pile.top() << std::endl;  // 20

    std::cout << "--- Copie vers std::stack ---" << std::endl;
    std::stack<int> standard(pile);
    std::cout << standard.top() << std::endl; // 20

    return 0;
}