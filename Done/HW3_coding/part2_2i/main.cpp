#include <iostream>

#include "CircularList.h"

int main()
{
    std::cout << "(a) will be demostrated after (b) and (c).\n";
    std::cout << "We will use three CircularList<int> l1, l2, and l3.\n";
    CircularList<int> l1, l2, l3;

    std::cout << "\n(b) InsertFront():\n";
    std::cout << "l1.InsertFront(4)\n";
    l1.InsertFront(4);
    std::cout << "l1.InsertFront(3)\n";
    l1.InsertFront(3);
    std::cout << "l1.InsertFront(2)\n";
    l1.InsertFront(2);
    std::cout << "l1.InsertFront(1)\n";
    l1.InsertFront(1);
    std::cout << "l1.InsertFront(0)\n";
    l1.InsertFront(0);
    std::cout << "l1: ";
    l1.Print();

    std::cout << "\n(c) InsertBack():\n";
    std::cout << "l1.InsertBack(5)\n";
    l1.InsertBack(5);
    std::cout << "l1.InsertBack(6)\n";
    l1.InsertBack(6);
    std::cout << "l1.InsertBack(7)\n";
    l1.InsertBack(7);
    std::cout << "l1.InsertBack(8)\n";
    l1.InsertBack(8);
    std::cout << "l1.InsertBack(9)\n";
    l1.InsertBack(9);
    std::cout << "l1: ";
    l1.Print();

    std::cout << "\n(a) Length():\n";
    std::cout << "l1.Length() = " << l1.Length() << '\n';

    std::cout << "\n(d) DeleteFront():\n";
    std::cout << "l1.DeleteFront()\n";
    l1.DeleteFront();
    std::cout << "l1: ";
    l1.Print();

    std::cout << "\n(e)DeleteBack():\n";
    std::cout << "l1.DeleteBack()\n";
    l1.DeleteBack();
    std::cout << "l1: ";
    l1.Print();

    std::cout << "\n(f) DeleteOdd():\n";
    std::cout << "l1.DeleteOdd()\n";
    l1.DeleteOdd();
    std::cout << "l1: ";
    l1.Print();

    std::cout
        << "\n(g) Split(CircularList<T>& L2, CircularListNode<T>*split):\n";
    std::cout << "For this question, we declare "
              << "Node<int> *split = new Node<int>(6) \n";
    Node<int> *split = new Node<int>(6);
    std::cout << "l1.Split(l2, split)\n";
    l1.Split(l2, split);
    std::cout << "l1: ";
    l1.Print();
    std::cout << "l2: ";
    l2.Print();

    std::cout << "\n(h) Merge<T>(CircularList<T>& L1, CircularList<T>& L2, "
              << "CircularList<T>& merged):\n";
    std::cout << "Merge(l1, l2, l3)\n";
    Merge(l1, l2, l3);
    std::cout << "l3: ";
    l3.Print();
    return 0;
}