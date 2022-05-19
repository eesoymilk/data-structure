#pragma once

#include <iostream>
#include <queue>
#include <stack>
#include <tuple>

template <class K, class E>
class BST;

template <class T>
class TreeNode
{
    template <class K, class E>
    friend class BST;
    T data;
    TreeNode<T>*left_child, *right_child;

public:
    TreeNode() {}
    TreeNode(const T& d, TreeNode<T>* l = nullptr, TreeNode<T>* r = nullptr)
        : data(d), left_child(l), right_child(r)
    {}
    ~TreeNode() {}
};

template <class K, class E>
class Dictionary
{
public:
    // return true if dictionary is empty
    virtual bool IsEmpty() const = 0;

    // return pointer to the pair with specified key;
    // return nullptr if no such pair
    virtual std::pair<K, E>* Get(const K&) const = 0;

    // insert the given pair; if key ia a duplicate, update associate element
    virtual void Insert(const std::pair<K, E>&) = 0;

    // delete pair with specified key
    virtual void Delete(const K&) = 0;
};

template <class K, class E>
using NODE = TreeNode<std::pair<K, E>>;

// objects: A finite set of nodes either empty or consisting of a root node,
// left BST and right BST.
template <class K, class E>
class BST : public Dictionary<K, E>
{
private:
    NODE<K, E>* root = nullptr;

    NODE<K, E>* Copy(NODE<K, E>* now) const;
    bool Equal(NODE<K, E>* l, NODE<K, E>* r);
    void DeleteNode(NODE<K, E>* del);
    void PrintNode(NODE<K, E>*);

public:
    // creates an empty BST
    BST() {}

    // copy constructor
    BST(BST<K, E>& a) { root = Copy(a.root); }

    // assignment
    BST<K, E> operator=(const BST& b) { return Equal(root, b.root); }

    // destructor
    ~BST() { DeleteNode(root); }

    // virtual functions
    bool IsEmpty() const { return root == nullptr; }
    std::pair<K, E>* Get(const K& k) const { return Get(root, k); }
    std::pair<K, E>* Get(NODE<K, E>*, const K&) const;
    void Insert(const std::pair<K, E>&);
    void Insert(NODE<K, E>*, const std::pair<K, E>&);
    void Delete(const K&);

    // return the left subtree of *this
    BST<K, E> LeftSubtree() { return BST<K, E>(Copy(root->left_child)); }

    // return the right subtree of *this
    BST<K, E> RightSubtree() { return BST<K, E>(Copy(root->right_child)); }

    // return the data in the root node of *this
    const std::pair<K, E>& RootData() { return root->data; }

    // traversal methods
    void Inorder() { Inorder(root); }
    void Inorder(NODE<K, E>*);
    void Preorder() { Preorder(root); }
    void Preorder(NODE<K, E>*);
    void Postorder() { Postorder(root); }
    void Postorder(NODE<K, E>*);
    void LevelOrder();

    // equality test
    bool operator==(const BST& b) const { return Equal(root, b.root); }

    std::pair<K, E>* RankGet(int r);
    void Split(const K& k, BST<K, E>& s, std::pair<K, E>*& m,
               BST<K, E>& b) const;
};

template <class K, class E>
std::pair<K, E>* BST<K, E>::Get(NODE<K, E>* p, const K& k) const
{
    if (!p) return nullptr;
    if (k < p->data.first) return Get(p->left_child, k);
    if (k > p->data.first) return Get(p->right_child, k);
    return &p->data;
}

template <class K, class E>
void BST<K, E>::Insert(const std::pair<K, E>& p)
{
    if (root) Insert(root, p);
    else root = new NODE<K, E>(p);
}

template <class K, class E>
void BST<K, E>::Insert(NODE<K, E>* now, const std::pair<K, E>& p)
{
    if (p.first > now->data.first) {
        if (now->right_child) Insert(now->right_child, p);
        else now->right_child = new NODE<K, E>(p);
    } else if (p.first < now->data.first) {
        if (now->left_child) Insert(now->left_child, p);
        else now->left_child = new NODE<K, E>(p);
    } else {
        now->data.second = p.second;
    }
}

template <class K, class E>
void BST<K, E>::Delete(const K& k)
{
    NODE<K, E>*del = root, *prev;
    while (del && k != del->data.first) {
        prev = del;
        if (k > del->data.first) del = del->right_child;
        else del = del->left_child;
    }
    if (!del) return;
    if (!del->left_child && !del->right_child) {
        prev->right_child = nullptr;
        delete del;
    } else if (del->left_child && del->right_child) {
        NODE<K, E>*succ = del->left_child, *prev = del;
        while (succ->right_child) {
            prev = succ;
            succ = succ->right_child;
        }
        del->data = succ->data;
        prev->right_child = succ->left_child;
        delete succ;
    } else {
        NODE<K, E>* nxt = del->left_child ? del->left_child : del->right_child;
        if (prev->left_child == del) prev->left_child = nxt;
        else prev->right_child = nxt;
        delete del;
    }
}

template <class K, class E>
std::pair<K, E>* BST<K, E>::RankGet(int r)
{
    std::stack<NODE<K, E>*> s;
    NODE<K, E>* now = root;

    while (now || !s.empty()) {
        while (now) {
            s.push(now);
            now = now->left_child;
        }
        now = s.top();
        s.pop();
        if (!r--) return &now->data;
        now = now->right_child;
    }
    return nullptr;
}

template <class K, class E>
void BST<K, E>::Split(const K& k, BST<K, E>& s, std::pair<K, E>*& m,
                      BST<K, E>& b) const
{
    NODE<K, E>*now = root, *s_now = s.root = nullptr, *b_now = b.root = nullptr;
    if (!root) return;
    while (now) {
        if (k < now->data.first) {
            NODE<K, E>* new_node =
                new NODE<K, E>(now->data, nullptr, Copy(now->right_child));
            if (!b.root) b_now = b.root = new_node;
            else b_now = b_now->left_child = new_node;
            now = now->left_child;
        } else if (k > now->data.first) {
            NODE<K, E>* new_node =
                new NODE<K, E>(now->data, Copy(now->left_child), nullptr);
            if (!s.root) s_now = s.root = new_node;
            else s_now = s_now->right_child = new_node;
            now = now->right_child;
        } else {
            if (!b.root) b_now = b.root = Copy(now->right_child);
            else b_now = b_now->left_child = Copy(now->right_child);
            if (!s.root) s_now = s.root = Copy(now->left_child);
            else s_now = s_now->right_child = Copy(now->left_child);
            m = new std::pair<int, char>(now->data);
            return;
        }
    }
    s.DeleteNode(s.root);
    b.DeleteNode(b.root);
    s.root = b.root = nullptr;
    m = nullptr;
}

template <class K, class E>
void BST<K, E>::Inorder(NODE<K, E>* now)
{
    if (!now) return;
    Inorder(now->left_child);
    PrintNode(now);
    Inorder(now->right_child);
    if (now == root) std::cout << '\n';
}

template <class K, class E>
void BST<K, E>::Preorder(NODE<K, E>* now)
{
    if (!now) return;
    PrintNode(now);
    Preorder(now->left_child);
    Preorder(now->right_child);
    if (now == root) std::cout << '\n';
}

template <class K, class E>
void BST<K, E>::Postorder(NODE<K, E>* now)
{
    if (!now) return;
    Postorder(now->left_child);
    Postorder(now->right_child);
    PrintNode(now);
    if (now == root) std::cout << '\n';
}

template <class K, class E>
void BST<K, E>::LevelOrder()
{
    std::queue<NODE<K, E>*> q;
    q.push(root);
    while (!q.empty()) {
        NODE<K, E>* now = q.front();
        q.pop();
        PrintNode(now);
        if (now->left_child) q.push(now->left_child);
        if (now->right_child) q.push(now->right_child);
    }
    std::cout << '\n';
}

// Private Methods of BST<K, E>

template <class K, class E>
NODE<K, E>* BST<K, E>::Copy(NODE<K, E>* now) const
{
    if (!now) return nullptr;
    return new NODE<K, E>(now->data, Copy(now->left_child),
                          Copy(now->right_child));
}

template <class K, class E>
bool BST<K, E>::Equal(NODE<K, E>* l, NODE<K, E>* r)
{
    if (!l && !r) return true;
    return l && r && l->data == r->data &&
           Equal(l->left_child, r->left_child) &&
           Equal(l->left_child, r->left_child);
}

template <class K, class E>
void BST<K, E>::DeleteNode(NODE<K, E>* del)
{
    if (!del) return;
    DeleteNode(del->left_child);
    DeleteNode(del->right_child);
    delete del;
}

template <class K, class E>
void BST<K, E>::PrintNode(NODE<K, E>* node)
{
    if (!node) return;
    std::cout << node->data;
}
