#include <iostream>

#include "Queue.h"

int main()
{
    Queue<int> q;
    std::cout << "Pushing [1, 2, 3, 4, 5] into q...\n";
    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    q.Push(5);
    std::cout << "q: " << q << std::endl;
    std::cout << "reverseQueue(q): " << reverseQueue(q) << std::endl;

    return 0;
}