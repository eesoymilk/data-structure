#include <iostream>
#include "Polynomial.h"

int main()
{
    // Polynomial p1, p2, p3, p4;

    // std::cin >> p1 >> p2;

    // std::cout << "p1: " << p1 << '\n';
    // std::cout << "p2: " << p2 << '\n';

    // p3 = p1.Add(p2);
    // std::cout << "p3 = p1 + p2: " << p3 << '\n';

    // p4 = p1.Mult(p2);
    // std::cout << "p4 = p1 * p2: " << p4 << '\n';

    Polynomial a, b, c;

    std::cout << "a(x) = ";
    std::cin >> a;
    std::cout << "b(x) = ";
    std::cin >> b;
    c = a.Mult(b);
    std::cout << "c(x) = a(x) * b(x)\n = " << c;

    return 0;
}