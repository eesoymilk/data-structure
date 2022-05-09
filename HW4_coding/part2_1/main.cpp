#include "BinaryTree.h"
#include <vector>

BinaryTree<int> BuildTree(std::vector<int>& vec)
{
	static int idx = 0;
	BinaryTree<int> b(vec[idx++]);
	TreeNode<int> *now = *b;
	while (idx < vec.size()) {
		b->leftChild = new TreeNode<int>(vec[idx++]);
		b->rightChild = new TreeNode<int>(vec[idx++]);
	}
}

int main()
{
	std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	BinaryTree<int> b = BuildTree(vec);
	return 0;
}
