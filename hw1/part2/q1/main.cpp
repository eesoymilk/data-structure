#include <iostream>
#include "global.h"
#include "Polynomial.h"

int main()
{
    Polynomial p1;

    p1.NewTerm(2.5, 3);
    p1.NewTerm(2, 1);

    std::cout << p1 << '\n';

    return 0;
}