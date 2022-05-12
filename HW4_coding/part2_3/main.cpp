#include <tuple>
#include <vector>

#include "BST.h"

std::ostream& operator<<(std::ostream& out, const std::pair<int, char>& p)
{
    out << '(' << p.first << ", " << p.second << ") ";
    return out;
}

int main()
{
    BST<int, char> b;
    std::vector<std::pair<int, char>> seq({{50, 'A'},
                                           {5, 'B'},
                                           {30, 'C'},
                                           {40, 'D'},
                                           {80, 'E'},
                                           {35, 'F'},
                                           {2, 'G'},
                                           {20, 'H'},
                                           {15, 'I'},
                                           {60, 'J'},
                                           {70, 'K'},
                                           {8, 'L'},
                                           {10, 'M'}});
    for (auto p : seq) b.Insert(p);
    b.Inorder();
    for (int i = 0; i < 13; i++) std::cout << *b.RankGet(i) << '\n';
    // b.Delete(50);
    // b.Inorder();
    return 0;
}