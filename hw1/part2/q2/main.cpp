#include <iostream>
#include "SparseMatrix.h"

int main()
{
    SparseMatrix sm1, sm2, sm3, sm4, sm5;

    std::cin >> sm1 >> sm2;
    std::cout << sm1.Add(sm2);

    // std::cout << "\nEnter two sparse matrice sm1 and sm2 with the same dimension\n";
    // std::cout << "\nsm1:\n";
    // std::cin >> sm1;
    // std::cout << "\nsm2:\n";
    // std::cin >> sm2;
    // std::cout << "\nEnter one sparse matrice sm3 with the same rows as sm1's columns\n";
    // std::cout << "\nsm3:\n";
    // std::cin >> sm3;

    // std::cout << "\nNow, sm4 = sm1 + sm2, sm5 = sm1 * sm3.\n";
    // sm4 = sm1.Add(sm2);
    // std::cout << "\nsm4:\n " << sm4 << '\n';
    // sm5 = sm1.Multiply(sm3);
    // std::cout << "\nsm5:\n " << sm5 << '\n';

    // std::cout << "\nFinally, let's transpose sm5.\n";
    // std::cout << "\nsm5^T:\n " << sm5.Transpose() << '\n';

    return 0;
}
