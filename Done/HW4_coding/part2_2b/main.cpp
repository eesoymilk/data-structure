#include <iostream>
#include <vector>

#include "MinHeap.h"

int main()
{
    std::vector<int> seq({50, 5, 30, 40, 80, 35, 2, 20, 15, 60, 70, 8, 10});
    MinHeap<int> h1(seq), h2;
    for (auto num : seq) h2.Push(num);
    std::cout << "h1 is constructed using bottom up method,\n"
              << "while h2 is constructed using 13 pushes.\n"
              << "h1: " << h1 << '\n'
              << "h2: " << h2 << '\n';

    std::cout << "\nNow let's test the function Pop() and Top()\n"
              << "h1.Top() = " << h1.Top() << '\n';

    h1.Pop();
    std::cout << "h1 after h1.Pop(): " << h1 << '\n'
              << "h1.Top() = " << h1.Top() << '\n';

    h1.Pop();
    std::cout << "h1 after h1.Pop(): " << h1 << '\n'
              << "h1.Top() = " << h1.Top() << '\n';

    return 0;
}