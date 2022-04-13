#include <iostream>

#include "Chain.h"

int main()
{
    Chain<int> l1, l2, l3;
    l1.InsertBack(1);
    l1.InsertBack(2);
    l1.InsertBack(3);
    l1.InsertBack(4);
    l1.InsertBack(5);
    l2.InsertBack(11);
    l2.InsertBack(12);
    l2.InsertBack(13);
    l2.InsertBack(14);
    l2.InsertBack(15);
    l2.InsertBack(16);
    l2.InsertBack(17);

    l3 = Merge(l1, l2);

    l3.Print();

    return 0;
}