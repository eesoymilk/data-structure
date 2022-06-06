#include <iostream>
#include <random>

#include "Sorting.h"

int main()
{
    int a[11] = {12, 2, 16, 30, 8, 28, 4, 10, 20, 6, 18};

    // PrintList(a, 11);
    QuickSort(a, 11, 0, 10);
    PrintList(a, 11);

    return 0;
}