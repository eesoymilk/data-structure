#include <iostream>

#include "Bag.h"

int main()
{
    // STACK
    std::cout << "Stack Showcase:\n";
    std::cout << "Stack<int>\n";
    Stack<int> s_int;
    std::cout << "Initially s_int.Size() = " << s_int.Size() << '\n';
    std::cout << "Pushing [1, 2, 3] into s_int...\n";
    s_int.Push(1);
    s_int.Push(2);
    s_int.Push(3);
    std::cout << "Now, s_int.Size() = " << s_int.Size() << '\n';
    std::cout << "Poping s_int...\n";
    s_int.Pop();
    std::cout << "Now, s_int.Size() = " << s_int.Size() << "\n\n";

    std::cout << "Stack<float>\n";
    Stack<float> s_float;
    std::cout << "Initially s_float.Size() = " << s_float.Size() << '\n';
    std::cout << "Pushing [0.1, 0.2, 0.3, 0.4] into s_float...\n";
    s_float.Push(0.1);
    s_float.Push(0.2);
    s_float.Push(0.3);
    s_float.Push(0.4);
    std::cout << "Now, s_float.Size() = " << s_float.Size() << '\n';
    std::cout << "Poping s_float...\n";
    s_float.Pop();
    std::cout << "Now, s_float.Size() = " << s_float.Size() << "\n";

    std::cout << "--------------------\n";

    // QUEUE
    std::cout << "Queue Showcase:\n";
    std::cout << "Queue<int>\n";
    Queue<int> q_int;
    std::cout << "Initially q_int.Size() = " << q_int.Size() << '\n';
    std::cout << "Pushing [1, 2, 3] into q_int...\n";
    q_int.Push(1);
    q_int.Push(2);
    q_int.Push(3);
    std::cout << "Now, q_int.Size() = " << q_int.Size() << '\n';
    std::cout << "Poping q_int...\n";
    q_int.Pop();
    std::cout << "Now, q_int.Size() = " << q_int.Size() << "\n\n";

    std::cout << "Queue<float>\n";
    Queue<float> q_float;
    std::cout << "Initially q_float.Size() = " << q_float.Size() << '\n';
    std::cout << "Pushing [0.1, 0.2, 0.3, 0.4] into q_float...\n";
    q_float.Push(0.1);
    q_float.Push(0.2);
    q_float.Push(0.3);
    q_float.Push(0.4);
    std::cout << "Now, q_float.Size() = " << q_float.Size() << '\n';
    std::cout << "Poping q_float...\n";
    q_float.Pop();
    std::cout << "Now, q_float.Size() = " << q_float.Size() << "\n";

    std::cout << "--------------------\n";

    // DEQUE
    std::cout << "Deque Showcase:\n";
    std::cout << "Deque<int>\n";
    Deque<int> d_int;
    std::cout << "Initially d_int.Size() = " << d_int.Size() << '\n';
    std::cout << "Add [1, 2, 3] from end of d_int...\n";
    d_int.Push(1);
    d_int.Push(2);
    d_int.Push(3);
    std::cout << "Now, d_int.Size() = " << d_int.Size() << ", "
              << "d_int.Front() = " << d_int.Front() << ", "
              << "and d_int.Rear() = " << d_int.Rear() << "\n";

    std::cout << "Add 0 from start of d_int...\n";
    d_int.PushFront(0);
    std::cout << "Now, d_int.Size() = " << d_int.Size() << ", "
              << "d_int.Front() = " << d_int.Front() << ", "
              << "and d_int.Rear() = " << d_int.Rear() << "\n";

    std::cout << "Delete an element from start of d_int...\n";
    d_int.Pop();
    std::cout << "Now, d_int.Size() = " << d_int.Size() << ", "
              << "d_int.Front() = " << d_int.Front() << ", "
              << "and d_int.Rear() = " << d_int.Rear() << "\n";

    std::cout << "Delete an element from end of d_int...\n";
    d_int.PopBack();
    std::cout << "Now, d_int.Size() = " << d_int.Size() << ", "
              << "d_int.Front() = " << d_int.Front() << ", "
              << "and d_int.Rear() = " << d_int.Rear() << "\n\n";

    std::cout << "Deque<float>\n";
    Deque<float> d_float;
    std::cout << "Initially d_float.Size() = " << d_float.Size() << '\n';
    std::cout << "Add [0.1, 0.2, 0.3] from end of d_float...\n";
    d_float.Push(0.1);
    d_float.Push(0.2);
    d_float.Push(0.3);
    std::cout << "Now, d_float.Size() = " << d_float.Size() << ", "
              << "d_float.Front() = " << d_float.Front() << ", "
              << "and d_float.Rear() = " << d_float.Rear() << "\n";

    std::cout << "Add 6.9 from start of d_float...\n";
    d_float.PushFront(6.9);
    std::cout << "Now, d_float.Size() = " << d_float.Size() << ", "
              << "d_float.Front() = " << d_float.Front() << ", "
              << "and d_float.Rear() = " << d_float.Rear() << "\n";

    std::cout << "Delete an element from start of d_float...\n";
    d_float.Pop();
    std::cout << "Now, d_float.Size() = " << d_float.Size() << ", "
              << "d_float.Front() = " << d_float.Front() << ", "
              << "and d_float.Rear() = " << d_float.Rear() << "\n";

    std::cout << "Delete an element from end of d_float...\n";
    d_float.PopBack();
    std::cout << "Now, d_float.Size() = " << d_float.Size() << ", "
              << "d_float.Front() = " << d_float.Front() << ", "
              << "and d_float.Rear() = " << d_float.Rear() << "\n";

    return 0;
}