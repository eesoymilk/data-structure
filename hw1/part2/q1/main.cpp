#include <iostream>
#include "Polynomial.h"

int main()
{
    Polynomial p1, p2, p3, p4;
    Coefficient x;

    std::cout << "Enter two polynomials p1 and p2,\n";
    std::cout << "p1: ";
    std::cin >> p1;
    std::cout << "p2: ";
    std::cin >> p2;

    std::cout << "Now, p3 = p1 + p2, p4 = p1 * p2.\n";
    p3 = p1.Add(p2);
    std::cout << "p3: " << p3 << '\n';
    p4 = p1.Mult(p2);
    std::cout << "p4: " << p4 << '\n';

    std::cout << "Finally, let's evaluate p4(x) at x = ";
    std::cin >> x;
    std::cout << "p4(" << x << ") = " << p4.Eval(x) << '\n';

    return 0;
}