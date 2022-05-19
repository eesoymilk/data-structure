#include "BinaryTree.h"

int main()
{
    using BT = BinaryTree<char>;
    BT a(BT(BT(BT(BT('A'), '-', BT('B')), '*', BT('C')), '*', BT('D')), '+',
         BT('E')),
        b(BT(BT(BT('H'), 'D', BT('J')), 'B', BT('E')), 'A',
          BT(BT('F'), 'C', BT('G')));
    std::cout
        << "For simplicity, I declared a type alias throughout this program\n"
           "\"using BT = BinaryTree<char>;\"\n";
    std::cout << "\nConstructors: BinaryTree(T& d) and\n"
                 "BinaryTree(BinaryTree<T>& bt1, T& d, BinaryTree<T>& bt2)\n"
                 "The 2 example binary trees are constructed as shown:\n"
                 "(Note that both constructors are used)\n"
                 "BT a(BT(BT(BT(BT('A'), '-', BT('B')), '*', BT('C')), '*', "
                 "BT('D')), '+', BT('E')),\n"
                 "   b(BT(BT(BT('H'), 'D', BT('J')), 'B', BT('E')), 'A', "
                 "BT(BT('F'), 'C', BT('G')));\n";

    std::cout << "\nTraversal Methods: "
                 "print both trees a and b in all fashions\n";
    std::cout << "a.Inorder():        ";
    a.Inorder();
    std::cout << "a.Preorder():       ";
    a.Preorder();
    std::cout << "a.Postorder():      ";
    a.Postorder();
    std::cout << "a.LevelOrder():     ";
    a.LevelOrder();
    std::cout << "a.NonrecInorder():  ";
    a.NonrecInorder();
    std::cout << "a.NoStackInorder(): ";
    a.NoStackInorder();

    std::cout << "\nb.Inorder():        ";
    b.Inorder();
    std::cout << "b.Preorder():       ";
    b.Preorder();
    std::cout << "b.Postorder():      ";
    b.Postorder();
    std::cout << "b.LevelOrder():     ";
    b.LevelOrder();
    std::cout << "b.NonrecInorder():  ";
    b.NonrecInorder();
    std::cout << "b.NoStackInorder(): ";
    b.NoStackInorder();

    std::cout << "\nCopy Constructor: BinaryTree(BinaryTree<T>& a)\n"
                 "Make a copy of both binary trees print them all."
                 "out in inorder fashion\n"
                 "BT a_copy(a);\n"
                 "BT b_copy(b);\n";
    BT a_copy(a);
    std::cout << "a.Inorder():      ";
    a.Inorder();
    std::cout << "a_copy.Inorder(): ";
    a_copy.Inorder();
    BT b_copy(b);
    std::cout << "b.Inorder():      ";
    b.Inorder();
    std::cout << "b_copy.Inorder(): ";
    b_copy.Inorder();

    std::cout << "\nDestructor: ~BinaryTree()\n"
                 "Since calling destructor manually is extremely unsafe,\n"
                 "only one example is provided.\n"
                 "Call the destructor of b_copy and try to print it,\n"
                 "and we shall see nothing being printed if destructor works.\n"
                 "b_copy.~BinaryTree();\n";
    b_copy.~BinaryTree();
    std::cout << "b_copy.Inorder(): ";
    b_copy.Inorder();

    std::cout << "\n\nisEmpty(): \n"
                 "(Note that b_copy is empty because it has been destructed)\n";
    std::cout << "a.isEmpty() = " << a.isEmpty() << '\n';
    std::cout << "b.isEmpty() = " << b.isEmpty() << '\n';
    std::cout << "a_copy.isEmpty() = " << a_copy.isEmpty() << '\n';
    std::cout << "b_copy.isEmpty() = " << b_copy.isEmpty() << '\n';

    std::cout << "\noperator==():\n";
    std::cout << "a == b: " << (a == b) << '\n';
    std::cout << "a == a.copy: " << (a == a_copy) << '\n';

    std::cout << "\nLeftSubtree() and RightSubtree():\n"
                 "Print (inorderly) both subtrees of a and b\n";
    std::cout << "a.LeftSubtree().Inorder():  ";
    a.LeftSubtree().Inorder();
    std::cout << "a.RightSubtree().Inorder(): ";
    a.RightSubtree().Inorder();
    std::cout << "b.LeftSubtree().Inorder():  ";
    b.LeftSubtree().Inorder();
    std::cout << "b.RightSubtree().Inorder(): ";
    b.RightSubtree().Inorder();

    std::cout << "\nRootData():\n";
    std::cout << "a.RootData() = " << a.RootData() << '\n';
    std::cout << "b.RootData() = " << b.RootData() << '\n';

    return 0;
}
