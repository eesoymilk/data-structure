#include <iostream>
#include <random>

#include "Sorting.h"

int main()
{
    int a[10] = {3, 4, 2, 1, 5, 7, 9, 0, 6, 8};

    for (int i = 0; i < 10; i++) std::cout << a[i] << " \n"[i == 9 ? 1 : 0];
    QuickSort(a, 0, 9);
    for (int i = 0; i < 10; i++) std::cout << a[i] << " \n"[i == 9 ? 1 : 0];

    return 0;
}