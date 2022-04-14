#include <iostream>

#include "CircularList.h"

int main()
{
    CircularList<int> cl;
    std::cout << cl.Length() << '\n';
    cl.InsertBack(1);
    cl.InsertBack(2);
    cl.InsertBack(3);
    cl.InsertBack(4);
    cl.InsertBack(5);
    cl.InsertBack(6);
    cl.InsertBack(7);
    cl.InsertBack(8);
    cl.Print();
    cl.DeleteOdd();
    cl.Print();
    return 0;
}