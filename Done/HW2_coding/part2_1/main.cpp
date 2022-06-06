#include "Queue.h"

int main()
{
    Queue<int> q1, q2, merged_queue;

    std::cout << "Initially, q1.IsEmpty() = " << q1.IsEmpty() << '\n';
    std::cout << "Pushing [1, 2, 3, 4, 5] into q1...\n";
    q1.Push(0);
    q1.Push(1);
    q1.Push(2);
    q1.Push(3);
    q1.Push(4);
    q1.Push(5);
    std::cout << "q1: " << q1 << '\n';
    std::cout << "Now, q1.IsEmpty() = " << q1.IsEmpty() << ", "
              << "q1.Size() = " << q1.Size() << ", "
              << "q1.Front() = " << q1.Front() << ", "
              << "q1.Rear() = " << q1.Rear() << "\n";
    std::cout << "Poping q1...\n";
    q1.Pop();
    std::cout << "q1: " << q1 << '\n';
    std::cout << "Now, q1.IsEmpty() = " << q1.IsEmpty() << ", "
              << "q1.Size() = " << q1.Size() << ", "
              << "q1.Front() = " << q1.Front() << ", "
              << "q1.Rear() = " << q1.Rear() << "\n\n";

    std::cout << "Pushing [6, 7, 8, 9, 10] into q2...\n";
    q2.Push(6);
    q2.Push(7);
    q2.Push(8);
    q2.Push(9);
    q2.Push(10);
    std::cout << "q2: " << q2 << "\n\n";

    std::cout << "merged_queue = Merge(q1, q2)\n";
    merged_queue = Merge(q1, q2);
    std::cout << "merged_queue: " << merged_queue << '\n';

    return 0;
}