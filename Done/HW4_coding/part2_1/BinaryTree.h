#pragma once

#include <iostream>
#include <queue>
#include <stack>

template <class T>
class BinaryTree;

template <class T>
class TreeNode
{
    friend class BinaryTree<T>;
    T data;
    TreeNode<T>*left_child, *right_child;

public:
    TreeNode() {}
    TreeNode(const T& d, TreeNode<T>* l = nullptr, TreeNode<T>* r = nullptr)
        : data(d), left_child(l), right_child(r)
    {}
    ~TreeNode() {}
};

// objects: A finite set of nodes either empty or consisting of a root node,
// left BinaryTree and right BinaryTree.
template <class T>
class BinaryTree
{
private:
    TreeNode<T>* root = nullptr;

    TreeNode<T>* Copy(TreeNode<T>* now) const;
    bool Equal(TreeNode<T>* l, TreeNode<T>* r) const;
    void DeleteNode(TreeNode<T>* del);
    void PrintNode(TreeNode<T>*) const;

public:
    // creates an empty binary tree
    BinaryTree() {}

    // creates an binary tree with one root given a data
    BinaryTree(const T& d) : root(new TreeNode<T>(d)) {}

    // creates an binary tree with one root given a node
    BinaryTree(TreeNode<T>* n) : root(n) {}

    // creates a binary tree whose left subtree is bt1, whose left subtree is
    // bt2, and whose root node contains d
    BinaryTree(const BinaryTree<T>& bt1, const T& d, const BinaryTree<T>& bt2)
        : root(new TreeNode<T>(d, Copy(bt1.root), Copy(bt2.root)))
    {}

    // copy constructor
    BinaryTree(const BinaryTree<T>& a) { root = Copy(a.root); }

    // assignment
    BinaryTree<T> operator=(const BinaryTree<T>& b) const
    {
        return Equal(root, b.root);
    }

    // destructor
    ~BinaryTree()
    {
        DeleteNode(root);
        root = nullptr;
    }

    // return true iff the binary tree is empty
    bool isEmpty() { return root == nullptr; }

    // return the left subtree of *this
    BinaryTree<T> LeftSubtree() const
    {
        return BinaryTree<T>(Copy(root->left_child));
    }

    // return the right subtree of *this
    BinaryTree<T> RightSubtree()
    {
        return BinaryTree<T>(Copy(root->right_child));
    }

    // return the data in the root node of *this
    const T& RootData() const { return root->data; }

    // traversal methods
    void Inorder() const { Inorder(root); }
    void Inorder(TreeNode<T>*) const;
    void Preorder() const { Preorder(root); }
    void Preorder(TreeNode<T>*) const;
    void Postorder() const { Postorder(root); }
    void Postorder(TreeNode<T>*) const;
    void LevelOrder() const;
    void NonrecInorder() const;
    void NoStackInorder() const;

    // equality test
    bool operator==(const BinaryTree& b) const { return Equal(root, b.root); }
};

template <class T>
void BinaryTree<T>::Inorder(TreeNode<T>* now) const
{
    if (!now) return;
    Inorder(now->left_child);
    PrintNode(now);
    Inorder(now->right_child);
    if (now == root) std::cout << '\n';
}

template <class T>
void BinaryTree<T>::Preorder(TreeNode<T>* now) const
{
    if (!now) return;
    PrintNode(now);
    Preorder(now->left_child);
    Preorder(now->right_child);
    if (now == root) std::cout << '\n';
}

template <class T>
void BinaryTree<T>::Postorder(TreeNode<T>* now) const
{
    if (!now) return;
    Postorder(now->left_child);
    Postorder(now->right_child);
    PrintNode(now);
    if (now == root) std::cout << '\n';
}

template <class T>
void BinaryTree<T>::LevelOrder() const
{
    std::queue<TreeNode<T>*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode<T>* now = q.front();
        q.pop();
        PrintNode(now);
        if (now->left_child) q.push(now->left_child);
        if (now->right_child) q.push(now->right_child);
    }
    std::cout << '\n';
}

template <class T>
void BinaryTree<T>::NonrecInorder() const
{
    std::stack<TreeNode<T>*> s;
    TreeNode<T>* now = root;

    while (now || !s.empty()) {
        while (now) {
            s.push(now);
            now = now->left_child;
        }
        now = s.top();
        s.pop();
        PrintNode(now);
        now = now->right_child;
    }
    std::cout << '\n';
}

template <class T>
void BinaryTree<T>::NoStackInorder() const
{
    if (!root) return;
    TreeNode<T>*top = nullptr, *last_right = nullptr, *p, *q, *r, *r1;
    p = q = root;
    while (true) {
        while (true) {
            if (!p->left_child && !p->right_child) {
                PrintNode(p);
                break;
            }
            if (!p->left_child) {
                PrintNode(p);
                r = p->right_child;
                p->right_child = q;
            } else {
                r = p->left_child;
                p->left_child = q;
            }
            q = p;
            p = r;
        }

        TreeNode<T>* av = p;
        while (true) {
            if (p == root) {
                std::cout << '\n';
                return;
            }
            if (!q->left_child) {
                r = q->left_child;
                q->left_child = p;
                p = q;
                q = r;
            } else if (!q->right_child) {
                r = q->left_child;
                q->left_child = p;
                p = q;
                q = r;
                PrintNode(p);
            } else if (q == last_right) {
                r = top;
                last_right = r->left_child;
                top = r->right_child;
                r->left_child = r->right_child = 0;
                r = q->right_child;
                q->right_child = p;
                p = q;
                q = r;
            } else {
                PrintNode(q);
                av->left_child = last_right;
                av->right_child = top;
                top = av;
                last_right = q;
                r = q->left_child;
                q->left_child = p;
                r1 = q->right_child;
                q->right_child = r;
                p = r1;
                break;
            }
        }
    }
}

// Private Methods of BinaryTree<T>

template <class T>
TreeNode<T>* BinaryTree<T>::Copy(TreeNode<T>* now) const
{
    if (!now) return nullptr;
    return new TreeNode<T>(now->data, Copy(now->left_child),
                           Copy(now->right_child));
}

template <class T>
bool BinaryTree<T>::Equal(TreeNode<T>* l, TreeNode<T>* r) const
{
    if (!l && !r) return true;
    return l && r && l->data == r->data &&
           Equal(l->left_child, r->left_child) &&
           Equal(l->left_child, r->left_child);
}

template <class T>
void BinaryTree<T>::DeleteNode(TreeNode<T>* del)
{
    if (!del) return;
    DeleteNode(del->left_child);
    DeleteNode(del->right_child);
    delete del;
}

template <class T>
void BinaryTree<T>::PrintNode(TreeNode<T>* node) const
{
    if (!node) return;
    std::cout << node->data;
}
