#include <tuple>
#include <vector>

#include "BST.h"

std::ostream& operator<<(std::ostream& out, const std::pair<int, char>& p)
{
    out << '(' << p.first << ", " << p.second << ") ";
    return out;
}

std::ostream& operator<<(std::ostream& out, const std::pair<int, char>* ptr)
{
    if (ptr) out << *ptr;
    else out << "the specified pair doesn't exist";
    return out;
}

int main()
{
    BST<int, char> bst, b, s;
    std::pair<int, char>* m;
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
    std::cout << "We utilize the std::pair in our aid for this problem,\n"
                 "the BST we are gonna build is of type BST<int, char>.\n"
                 "The below init statements show variables used.\n"
                 "BST<int, char> bst, b, s;\n"
                 "std::pair<int, char>* m;\n"
                 "std::vector<std::pair<int, char>> seq({...})\n"
                 "(elements of seq are shown below)\n"
                 "Each integer of the sequence provided is assigned a char.\n";
    std::cout << "key:   ";
    for (auto [k, v] : seq) std::cout << " \0"[k / 10 ? 1 : 0] << k << ' ';
    std::cout << "\nvalue:  ";
    for (auto [k, v] : seq) std::cout << v << "  ";
    std::cout << "\n\n";

    std::cout << "Constructing the BST: \n"
                 "Inserting the sequence into bst one by one,\n"
                 "during which the default constructer and \n"
                 "Insert(const std::pair<K, E>&) are used.\n";
    "for (auto p : seq) bst.Insert(p);\n";
    for (auto p : seq) bst.Insert(p);
    std::cout << "bst.Inorder(): ";
    bst.Inorder();

    std::cout << "\nIsEmpty(): \n";
    std::cout << "bst.IsEmpty() = " << bst.IsEmpty() << '\n';
    std::cout << "b.IsEmpty() = " << b.IsEmpty() << '\n';
    std::cout << "s.IsEmpty() = " << s.IsEmpty() << '\n';

    std::cout << "\nGet(const K& k): \n";
    std::cout << "bst.Get(40): " << bst.Get(40) << '\n';
    std::cout << "bst.Get(8):  " << bst.Get(8) << '\n';
    std::cout << "bst.Get(69): " << bst.Get(69) << '\n';

    std::cout << "\nDelete(const K& k):\n"
                 "We will prove that it works by \n"
                 "Get() a existing key then delete it, \n"
                 ",Get() it again to show that it's been deleted.\n"
                 "ultimately print the bst inorderly.\n"
                 "Also, all three cases of delete are provided.\n"
                 "Note: a copy of the original bst is used for this problem "
                 "for future purposes.\n"
                 "BST<int, char> bst_copy(bst);\n\n";

    BST<int, char> bst_copy(bst);
    std::cout << "bst_copy: ";
    bst_copy.Inorder();

    std::cout << "\nCase 1: Delete a node with NO child.\n";
    std::cout << "bst_copy.Get(10): " << bst_copy.Get(10) << '\n';
    std::cout << "bst_copy.Delete(10)\n";
    bst_copy.Delete(10);
    std::cout << "bst_copy.Get(10): " << bst_copy.Get(10) << '\n';
    std::cout << "bst_copy: ";
    bst_copy.Inorder();

    std::cout << "\nCase 2: Delete a node with ONE child.\n";
    std::cout << "bst_copy.Get(15): " << bst_copy.Get(15) << '\n';
    std::cout << "bst_copy.Delete(15)\n";
    bst_copy.Delete(15);
    std::cout << "bst_copy.Get(15): " << bst_copy.Get(15) << '\n';
    std::cout << "bst_copy: ";
    bst_copy.Inorder();

    std::cout << "\nCase 3: Delete a node with TWO child.\n";
    std::cout << "bst_copy.Get(50): " << bst_copy.Get(50) << '\n';
    std::cout << "bst_copy.Delete(50)\n";
    bst_copy.Delete(50);
    std::cout << "bst_copy.Get(50): " << bst_copy.Get(50) << '\n';
    std::cout << "bst_copy: ";
    bst_copy.Inorder();

    std::cout << "\nRankGet(int r):\n";
    std::cout << "bst(for reference): ";
    bst_copy.Inorder();
    std::cout << "bst.RankGet(0):  " << bst.RankGet(0) << '\n';
    std::cout << "bst.RankGet(5):  " << bst.RankGet(5) << '\n';
    std::cout << "bst.RankGet(12): " << bst.RankGet(12) << '\n';
    std::cout << "bst.RankGet(13): " << bst.RankGet(13) << '\n';
    std::cout << "bst.RankGet(50): " << bst.RankGet(50) << '\n';

    std::cout
        << "\nSplit(const K& k, BST<K, E>& s, pair<K, E>*& m, BST<K, E>& b):\n"
           "Split the tree and print all things out.\n"
           "Note that the original bst is not modified at all.\n";
    std::cout << "\nDemo 1: k = 50\n"
                 "bst.Split(50, s, m, b);\n";
    bst.Split(50, s, m, b);
    std::cout << "bst: ";
    bst.Inorder();
    std::cout << "s:   ";
    s.Inorder();
    std::cout << "m:   " << m << '\n';
    std::cout << "b:   ";
    b.Inorder();

    std::cout << "\nDemo 2: k = 35\n"
                 "bst.Split(35, s, m, b);\n";
    bst.Split(35, s, m, b);
    std::cout << "bst: ";
    bst.Inorder();
    std::cout << "s:   ";
    s.Inorder();
    std::cout << "m:   " << m << '\n';
    std::cout << "b:   ";
    b.Inorder();

    std::cout << "\nDemo 3: k = 15\n"
                 "bst.Split(15, s, m, b);\n";
    bst.Split(15, s, m, b);
    std::cout << "bst: ";
    bst.Inorder();
    std::cout << "s:   ";
    s.Inorder();
    std::cout << "m:   " << m << '\n';
    std::cout << "b:   ";
    b.Inorder();
    // bst.Split(14, b, m, s);
    // bst.Inorder();
    // b.Inorder();
    // std::cout << *m << '\n';
    // s.Inorder();
    // for (int i = 0; i < 13; i++) std::cout << *b.RankGet(i) << '\n';
    // b.Delete(50);
    // b.Inorder();
    return 0;
}