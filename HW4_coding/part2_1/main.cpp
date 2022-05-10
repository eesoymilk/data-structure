#include "BinaryTree.h"

using BT = BinaryTree<char>;

int main()
{
    BT a(BT(BT(BT(BT('A'), '-', BT('B')), '*', BT('C')), '*', BT('D')), '+',
         BT('E')),
        b(BT(BT(BT('H'), 'D', BT('J')), 'B', BT('E')), 'A',
          BT(BT('F'), 'C', BT('G')));
    a.Inorder();
    a.LeftSubtree().Inorder();
    b.LevelOrder();
    a.NoStackInorder();
    return 0;
}
