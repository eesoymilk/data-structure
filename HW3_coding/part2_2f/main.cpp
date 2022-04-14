#include <iostream>

#include "CircularList.h"

int main()
{
    CircularList<int> cl1, cl2, cl3;
    // std::cout << "Hello" << '\n';
    cl1.InsertFront(1);
    cl1.InsertFront(2);
    cl1.InsertFront(3);
    cl1.InsertFront(4);
    cl1.InsertFront(5);
    cl2.InsertFront(6);
    cl2.InsertFront(7);
    cl2.InsertFront(8);
    cl2.InsertFront(9);
    cl2.InsertFront(10);
    cl3 = Merge(cl1, cl2);
    cl3.Print();
    // cl.Patch(3, 2);
    // cl.Print();
    // cl.DeleteBack();
    // cl.Print();
    // cl.DeleteBack();
    // cl.Print();
    // cl.DeleteBack();
    // cl.Print();
    // cl.InsertBack(6);
    // cl.InsertBack(7);
    // cl.InsertBack(8);
    // cl.Print();
    // std::cout << cl.Length() << '\n';
    return 0;
}