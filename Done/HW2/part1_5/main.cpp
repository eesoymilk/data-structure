#include <iostream>
#include <queue>
#include <stack>

enum TRADE_MONTHS { Jan, Apr, Jun, Sep, Nov };

// Price per shar in TRADE MONTHS: Jan, Apr, Jun, Sep, Nov
const int PricePerShare[5] = {10, 30, 20, 50, 30};

int main()
{
    std::queue<int> q;
    std::stack<int> s;
    int capital_FIFO = 0, capital_LIFO = 0;

    // first-in-first-out: Keep stock certificates in a queue
    q.push(PricePerShare[Jan] * 100);
    q.push(PricePerShare[Apr] * 100);
    q.push(PricePerShare[Sep] * 100);
    capital_FIFO += PricePerShare[Jun] * 100 - q.front();
    q.pop();
    capital_FIFO += PricePerShare[Nov] * 100 - q.front();
    q.pop();

    // last-in-first-out: Keep stock certificates in a stack
    s.push(PricePerShare[Jan] * 100);
    s.push(PricePerShare[Apr] * 100);
    s.push(PricePerShare[Sep] * 100);
    capital_LIFO += PricePerShare[Jun] * 100 - s.top();
    s.pop();
    capital_LIFO += PricePerShare[Nov] * 100 - s.top();
    s.pop();

    std::cout << "FIFO (first-in, first-out): ";
    if (capital_FIFO >= 0)
        std::cout << "gain";
    else
        std::cout << "loss";
    std::cout << " $" << std::abs(capital_FIFO) << '\n';

    std::cout << "LIFO (last-in, first-out) : ";
    if (capital_LIFO >= 0)
        std::cout << "gain $" << capital_LIFO;
    else
        std::cout << "loss";
    std::cout << " $" << std::abs(capital_LIFO) << '\n';

    return 0;
}