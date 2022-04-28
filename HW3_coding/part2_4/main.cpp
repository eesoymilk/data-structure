#include "Polynomial.h"

int main()
{
    Polynomial p, p1;
    std::cin >> p;
    std::cout << p;
    Polynomial p2 = p;
    std::cout << p2;
    p1 = p;
    std::cout << p1;
    std::cin.get();
    return 0;
}