#include <iostream>
#include <stack>

int PermutationCount;

enum OPERATION
{
    POP_INIT,
    POP_MID,
};

inline void PrintStack(std::stack<int> s)
{
    for (; !s.empty(); s.pop())
        std::cout << s.top() << " \n"[s.size() == 1 ? 1 : 0];
}

void SwitchRailroad(std::stack<int> init,
                    std::stack<int> mid = std::stack<int>{},
                    std::stack<int> dest = std::stack<int>{},
                    int op = OPERATION::POP_INIT)
{
    if (op == OPERATION::POP_INIT) {
        mid.push(init.top());
        init.pop();
    } else if (op == OPERATION::POP_MID) {
        dest.push(mid.top());
        mid.pop();
    }

    if (!init.empty()) SwitchRailroad(init, mid, dest, OPERATION::POP_INIT);
    if (!mid.empty()) SwitchRailroad(init, mid, dest, OPERATION::POP_MID);
    if (init.empty() && mid.empty()) {
        std::cout << "Stack Permutation #" << ++PermutationCount << ": ";
        PrintStack(dest);
    }
}

int main()
{
    std::cout << "When n = 3\n";
    SwitchRailroad(std::stack<int>({3, 2, 1}));

    PermutationCount = 0;
    std::cout << "\nWhen n = 4\n";
    SwitchRailroad(std::stack<int>({4, 3, 2, 1}));

    return 0;
}