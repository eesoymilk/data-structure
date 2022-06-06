#include <iostream>
#include <stack>

int PermutationCount;

enum OPERATION { POP_INIT, POP_MID };

// Print out the given stack s
inline void PrintStack(std::stack<int> s)
{
    for (; !s.empty(); s.pop())
        std::cout << s.top() << " \n"[s.size() == 1 ? 1 : 0];
}

// Recursive function that switches cars from right railway to the left
// init stack: right track where the cars initially rested
// mid stack: vertical track in the middle
// dest stack: left track which is the destination of the cars
// op: whether to pop init to mid or to pop mid to dest
void SwitchRailroad(std::stack<int> init,
                    std::stack<int> mid = std::stack<int>{},
                    std::stack<int> dest = std::stack<int>{},
                    int op = OPERATION::POP_INIT)
{
    // Manipulate the stacks according to op
    if (op == OPERATION::POP_INIT) {
        mid.push(init.top());
        init.pop();
    } else if (op == OPERATION::POP_MID) {
        dest.push(mid.top());
        mid.pop();
    }

    // Switch the railroad recursively
    if (!init.empty()) SwitchRailroad(init, mid, dest, OPERATION::POP_INIT);
    if (!mid.empty()) SwitchRailroad(init, mid, dest, OPERATION::POP_MID);
    if (init.empty() && mid.empty()) {
        std::cout << "permutation #" << ++PermutationCount << ": ";
        PrintStack(dest);
    }
}

int main()
{
    // Case when there are 3 cars
    std::cout << "For n = 3\n";
    SwitchRailroad(std::stack<int>({3, 2, 1}));
    std::cout << "There are total " << PermutationCount
              << " possible permutations.\n\n";
    PermutationCount = 0;

    // Case when there are 4 cars
    std::cout << "For n = 4\n";
    SwitchRailroad(std::stack<int>({4, 3, 2, 1}));
    std::cout << "There are total " << PermutationCount
              << " possible permutations.\n\n";

    return 0;
}