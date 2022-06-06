#include <iostream>

#include "Chain.h"

int main()
{
    std::cout << "(a) will be demostrated in the end.\n";
    std::cout << "For (b) to (l), we will use two Chain<int> l1 and l2.\n";

    Chain<int> l1, l2;

    std::cout << "\n(b) InsertFront():\n";
    std::cout << "l1.InsertFront(5)\n";
    l1.InsertFront(5);
    std::cout << "l1.InsertFront(4)\n";
    l1.InsertFront(4);
    std::cout << "l1.InsertFront(3)\n";
    l1.InsertFront(3);
    std::cout << "l1.InsertFront(2)\n";
    l1.InsertFront(2);
    std::cout << "l1.InsertFront(1)\n";
    l1.InsertFront(1);
    std::cout << "l1: ";
    l1.Print();

    std::cout << "\n(c) DeleteFront() and DeleteBack():\n";
    std::cout << "l1.DeleteFront()\n";
    l1.DeleteFront();
    std::cout << "l1.DeleteBack()\n";
    l1.DeleteBack();
    std::cout << "l1: ";
    l1.Print();

    std::cout << "\n(d) Front() and Back():\n";
    std::cout << "l1.Front() = " << l1.Front() << ", l1.Back() = " << l1.Back()
              << '\n';

    std::cout << "\n(e) Get(int i):\n";
    std::cout << "l1.Get(1) = " << l1.Get(1) << '\n';

    std::cout << "\n(f) Delete(int i):\n";
    std::cout << "l1.Delete(1)\n";
    l1.Delete(1);
    std::cout << "l1: ";
    l1.Print();

    std::cout << "\n(g) Insert(int i, T e):\n";
    std::cout << "l1.Insert(2, 69)\n";
    l1.Insert(2, 69);
    std::cout << "l1.Insert(3, 420)\n";
    l1.Insert(3, 420);
    std::cout << "l1: ";
    l1.Print();

    std::cout << "\n(h) Length():\n";
    std::cout << "l1.Length() = " << l1.Length() << '\n';

    std::cout << "\n(i) Patch(int i, T e):\n";
    std::cout << "l1.Patch(1, 72)\n";
    l1.Patch(1, 72);
    std::cout << "l1.Patch(4, 87)\n";
    l1.Patch(4, 87);
    std::cout << "l1: ";
    l1.Print();

    std::cout << "\n(j) Insert(int i, T e):\n";
    std::cout << "l1.Insert(1, 100)\n";
    l1.Insert(1, 100);
    std::cout << "l1: ";
    l1.Print();

    std::cout << "\n(k) DeleteOdd():\n";
    std::cout << "l1.DeleteOdd()\n";
    l1.DeleteOdd();
    std::cout << "l1: ";
    l1.Print();

    std::cout << "\n(l) divideMid(Chain<T>& subList):\n";
    std::cout << "l1.divideMid(l2)\n";
    l1.divideMid(l2);
    std::cout << "l1: ";
    l1.Print();
    std::cout << "l2: ";
    l2.Print();

    std::cout << "For (m) and (n), we will use two Chain<int> l3 and l4, \n";
    std::cout << "and one ChainNode<int>* split.\n";

    Chain<int> l3, l4, l5;
    ChainNode<int> *split = new ChainNode<int>(3);
    l3.InsertFront(5);
    std::cout << "l3.InsertFront(4)\n";
    l3.InsertFront(4);
    std::cout << "l3.InsertFront(3)\n";
    l3.InsertFront(3);
    std::cout << "l3.InsertFront(2)\n";
    l3.InsertFront(2);
    std::cout << "l3.InsertFront(1)\n";
    l3.InsertFront(1);
    std::cout << "l3: ";
    l3.Print();

    std::cout << "\n(m) Split(Chain<T>& L2, ChainNode<T>* split):\n";
    std::cout << "split = new ChainNode<int>(3)\n";
    std::cout << "l3.Split(l4, split)\n";
    l3.Split(l4, split);
    std::cout << "l3: ";
    l3.Print();
    std::cout << "l4: ";
    l4.Print();

    std::cout
        << "\n(n) Merge<T>(Chain<T> L1, Chain<T> L2, Chain<T>& merged):\n";
    std::cout << "Merge(l3, l4, l5)\n";
    Merge(l3, l4, l5);
    std::cout << "l5: ";
    l5.Print();

    std::cout << "\n(a) ~Chain():\n";
    std::cout << "Let's call all destructors and print the lists.\n";
    std::cout << "l1.~Chain()\n";
    l1.~Chain();
    std::cout << "l1: ";
    l1.Print();
    std::cout << "l2.~Chain()\n";
    l2.~Chain();
    std::cout << "l2: ";
    l2.Print();
    std::cout << "l3.~Chain()\n";
    l3.~Chain();
    std::cout << "l3: ";
    l3.Print();
    std::cout << "l4.~Chain()\n";
    l4.~Chain();
    std::cout << "l4: ";
    l4.Print();
    std::cout << "l5.~Chain()\n";
    l5.~Chain();
    std::cout << "l5: ";
    l5.Print();

    return 0;
}