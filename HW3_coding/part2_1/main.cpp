#include <iostream>

#include "Chain.h"

int main()
{
    Chain<int> l1, l2, l3;
    l2.InsertBack(1);
    l2.InsertBack(2);
    l2.InsertBack(3);
    l2.InsertBack(4);
    l2.InsertBack(5);
    l2.InsertBack(6);
    l2.InsertBack(7);
    // l2.InsertBack(8);
    l2.Print();

    l2.divideMid(l3);

    l2.Print();
    l3.Print();

    // l3 = Merge(l1, l2);

    // l3.Print();

    return 0;
}