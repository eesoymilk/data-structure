#include <iostream>

#include "List.h"

int Eval(List<int> l)
{
    List<int>::Iterator it1 = l.Begin(), it2 = l.Begin() + 5;
    int result = 0;
    while (it2 != l.End()) {
        result += (*it1) * (*it2);
        it1++;
        it2++;
    }
    return result;
}

int main()
{
    std::cout << "(a) will be demostrated in the end.\n";
    std::cout << "For (b) to (i), and (l), "
              << "we will use two List<int> l1 and l2.\n";

    List<int> l1, l2;

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
    std::cout << "l1: " << l1;

    std::cout << "\n(bonus) InsertBack():\n";
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
    std::cout << "l1: " << l1;

    std::cout << "\n(c) DeleteFront() and DeleteBack():\n";
    std::cout << "l1.DeleteFront()\n";
    l1.DeleteFront();
    std::cout << "l1.DeleteBack()\n";
    l1.DeleteBack();
    std::cout << "l1: " << l1;

    std::cout << "\n(d) Front() and Back():\n";
    std::cout << "l1.Front() = " << l1.Front() << ", "
              << "l1.Back() = " << l1.Back() << '\n';

    std::cout << "\n(e) Get(int i):\n";
    std::cout << "l1.Get(4) = " << l1.Get(4) << '\n';

    std::cout << "\n(f) Delete(int i):\n";
    std::cout << "l1.Delete(1)\n";
    l1.Delete(1);
    std::cout << "l1: " << l1;

    std::cout << "\n(g) Insert(int i, T e):\n";
    std::cout << "l1.Insert(2, 69)\n";
    l1.Insert(2, 69);
    std::cout << "l1.Insert(3, 420)\n";
    l1.Insert(3, 420);
    std::cout << "l1: " << l1;

    std::cout << "\n(h) std::ostream &operator<<(std::ostream &out, "
              << "const List<T> &l):\n";
    std::cout << "Note that all list printed "
              << "in this demo is using operator<< to print,\n"
              << "and therefore, there's no need show demo here.\n";

    std::cout << "\n(i) Note that Begin() and End() are shown in operator<<.\n"
              << "Therefore, here I'll show "
              << "InsertBack(T& e), Concatenate(List<T>& b), and Reverse().\n";

    std::cout << "(i)-(1) InsertBack(T& e):\n";
    std::cout << "l2.InsertBack(5)\n";
    l2.InsertBack(5);
    std::cout << "l2.InsertBack(6)\n";
    l2.InsertBack(6);
    std::cout << "l2.InsertBack(7)\n";
    l2.InsertBack(7);
    std::cout << "l2.InsertBack(8)\n";
    l2.InsertBack(8);
    std::cout << "l2.InsertBack(9)\n";
    l2.InsertBack(9);
    std::cout << "l2: " << l2;
    std::cout << "(i)-(2) Concatenate(List<T>& b):\n";
    std::cout << "l1.Concatenate(l2)\n";
    l1.Concatenate(l2);
    std::cout << "l1: " << l1;
    std::cout << "(i)-(3) Reverse():\n";
    std::cout << "l2.Reverse()\n";
    l2.Reverse();
    std::cout << "l2: " << l2;

    std::cout << "\n(j) stack\n"
              << "For question (j), we will use a Stack<int> s,\n"
              << "and test the basic functionalities of a stack, "
              << "which are Push(const T& e), Size(), "
              << "IsEmpty(), Top(), and Pop().";

    Stack<int> s;

    std::cout << "(j)-(1) Push():\n";
    std::cout << "s.Push(0)\n";
    s.Push(0);
    std::cout << "s.Push(1)\n";
    s.Push(1);
    std::cout << "s.Push(2)\n";
    s.Push(2);
    std::cout << "s.Push(3)\n";
    s.Push(3);
    std::cout << "s.Push(4)\n";
    s.Push(4);
    std::cout << "s: " << s;

    std::cout << "(j)-(2) Size():\n";
    std::cout << "s.Size() = " << s.Size() << '\n';

    std::cout << "(j)-(3) IsEmpty():\n";
    std::cout << "s.IsEmpty() = " << s.IsEmpty() << '\n';

    std::cout << "(j)-(4) Top():\n";
    std::cout << "s.Top() = " << s.Top() << '\n';

    std::cout << "(j)-(5) Pop():\n";
    std::cout << "s.Pop()\n";
    s.Pop();
    std::cout << "s: " << s;
    std::cout << "s.Pop()\n";
    s.Pop();
    std::cout << "s: " << s;
    std::cout << "s.Pop()\n";
    s.Pop();
    std::cout << "s: " << s;

    std::cout << "\n(k) queue\n"
              << "For question (k), we will use a Queue<int> q,\n"
              << "and test the basic functionalities of a queue, "
              << "which are Push(const T& e), Size(), "
              << "IsEmpty(), Front(), Rear(), and Pop().";

    Queue<int> q;

    std::cout << "(k)-(1) Push():\n";
    std::cout << "q.Push(0)\n";
    q.Push(0);
    std::cout << "q.Push(1)\n";
    q.Push(1);
    std::cout << "q.Push(2)\n";
    q.Push(2);
    std::cout << "q.Push(3)\n";
    q.Push(3);
    std::cout << "q.Push(4)\n";
    q.Push(4);
    std::cout << "q: " << q;

    std::cout << "(k)-(2) Size():\n";
    std::cout << "q.Size() = " << q.Size() << '\n';

    std::cout << "(k)-(3) IsEmpty():\n";
    std::cout << "q.IsEmpty() = " << q.IsEmpty() << '\n';

    std::cout << "(k)-(4) Front():\n";
    std::cout << "q.Front() = " << q.Front() << '\n';

    std::cout << "(k)-(5) Rear():\n";
    std::cout << "q.Rear() = " << q.Rear() << '\n';

    std::cout << "(k)-(6) Pop():\n";
    std::cout << "q.Pop()\n";
    q.Pop();
    std::cout << "q: " << q;
    std::cout << "q.Pop()\n";
    q.Pop();
    std::cout << "q: " << q;
    std::cout << "q.Pop()\n";
    q.Pop();
    std::cout << "q: " << q;

    std::cout << "\n(l) Eval(List<int> l):\n";
    std::cout << "l1: " << l1;
    std::cout << "Eval(l1) = " << Eval(l1) << '\n';

    std::cout << "\n(a) ~List():\n";
    std::cout << "Let's call all destructors and print the lists.\n";
    std::cout << "l1.~List()\n";
    l1.~List();
    std::cout << "l1: " << l1;
    std::cout << "l2.~List()\n";
    l2.~List();
    std::cout << "l2: " << l2;

    return 0;
}
