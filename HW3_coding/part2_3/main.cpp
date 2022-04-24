#include <iostream>

#include "List.h"

template <class T>
void Print(List<T> l)
{
    for (typename List<T>::Iterator it = l.Begin(); it != l.End(); it++)
        std::cout << *it << " \n"[it.IsLastElement() ? 1 : 0];
}

int Eval(List<int> l)
{
    List<int>::Iterator it1 = l.Begin(), it2 = l.Begin() + 5;
    int result = 0;
    while (it2 != l.End())
    {
        result += (*it1) * (*it2);
        it1++;
        it2++;
    }
    return result;
}

int main()
{
    List<int> l1, l2;

    l1.InsertBack(1);
    l1.InsertBack(2);
    l1.InsertBack(3);
    l1.InsertBack(4);
    l1.InsertBack(5);
    l2.InsertBack(6);
    l2.InsertBack(7);
    l2.InsertBack(8);
    l2.InsertBack(9);
    l2.InsertBack(10);

    Print(l1);
    Print(l2);
    l1.Concatenate(l2);
    Print(l1);
    l1.Reverse();
    Print(l1);
    std::cout << Eval(l1) << '\n';

    return 0;
}
