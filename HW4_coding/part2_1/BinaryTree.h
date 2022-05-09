#pragma once

template <class T>
class BinaryTree;

template <class T>
class TreeNode
{
	friend class BinaryTree<T>;
public:
	T data;
	TreeNode<T> *leftChild, *rightChild;

	TreeNode() {}
	TreeNode(T& d, TreeNode<T>* l = nullptr, TreeNode<T>* r = nullptr)
		: data(d), leftChild(l), rightChild(r) {}
	~TreeNode();
};

// template<class T>
// TreeNode<T>::TreeNode(T& d): data(d)
// {
// }

template<class T>
TreeNode<T>::~TreeNode()
{
}

// objects: A finite set of nodes either empty or consisting of a root node,
// left BinaryTree and right BinaryTree.
template <class T>
class BinaryTree
{
private:
	TreeNode<T> *root = nullptr;
public:
	// creates an empty binary tree
  	BinaryTree() {}

	// creates an binary tree one root
  	BinaryTree(T& item): root(new TreeNode<T>(item)) {}

	// creates a binary tree whose left subtree is bt1, whose left subtree is
	// bt2, and whose root node contains item
  	BinaryTree(BinaryTree<T>& bt1, T& item, BinaryTree<T>& bt2);

	//
  	~BinaryTree() {}

	//
	TreeNode<T>* operator->() { return root; }
	TreeNode<T>* operator*() { return root; }

	// return true iff the binary tree is empty
	bool isEmpty() { return root == nullptr; }

	// return the left subtree of *this
	BinaryTree<T> LeftSubtree();

	// return the right subtree of *this
	BinaryTree<T> RightSubtree();

	// return the data in the root node of *this
	T RootData();

	void Inorder();
	void Preorder();
	void Postorder();
	void LevelOrder();
	void NonrecInorder();
	void NoStackInorder();
	bool operator==(const BinaryTree& t) const;
};

// template <class T>
// BinaryTree<T>::BinaryTree(T& item)
// {
// }
