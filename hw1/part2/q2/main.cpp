#include <iostream>
#include "SparseMatrix.h"

int main()
{
    SparseMatrix test_sm;
    
    std::cout << "Testing iostream for sparse matrix...\n";
    std::cin >> test_sm;
    std::cout << test_sm;
    std::cout << "Transposing...\n";
    std::cout << test_sm.Transpose();

    return 0;
}