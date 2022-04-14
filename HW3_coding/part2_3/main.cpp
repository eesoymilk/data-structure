#include <iostream>

#include "List.h"

int main()
{
    List<int> l;
    // Queue<int> q;

    // q.Push(1);
    // q.Push(2);
    // q.Push(3);
    // q.Push(4);
    // for (auto it = q.Begin(); it != q.End(); ++it) std::cout << *it << ' ';
    // std::cout << '\n';
    // q.Pop();
    // for (auto it = q.Begin(); it != q.End(); ++it) std::cout << *it << ' ';
    // std::cout << '\n';
    // PrintLinkedList(s);

    l.InsertBack(1);
    l.InsertBack(2);
    l.InsertBack(3);
    l.InsertBack(4);
    l.InsertBack(5);
    l.InsertBack(6);
    l.InsertBack(7);
    l.InsertBack(8);
    l.InsertBack(9);
    l.InsertBack(10);
    l.InsertBack(11);
    l.InsertBack(12);

    int result = 0;
    // Initializing the iterators
    List<int>::Iterator iter_i = l.Begin();
    List<int>::Iterator iter_i_plus_5 = l.Begin();

    // let this iterator be 5 nodes ahead
    for (int i = 0; i < 5; i++) ++iter_i_plus_5;

    // loop through the list and add the products as instructed
    while (iter_i != l.End() && iter_i_plus_5 != l.End()) {
        result += *iter_i * *iter_i_plus_5;
        ++iter_i;
        ++iter_i_plus_5;
    }

    // output the result
    std::cout << result << '\n';

    return 0;
}