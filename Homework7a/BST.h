#pragma once

#include <functional>

template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;
        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };
    Node* root;
    size_t _size;
    BST(): root(nullptr), _size(0) {
        // implement the constructor here
    }

    ~BST() {
        // implement the destructor here
        destroyTree(root);
        root = nullptr;
    }
    void destroyTree(Node* r) {
        if (r != nullptr) {
            destroyTree(r->left);
            destroyTree(r->right);
            delete r;
        }
    }
    const Node* getRootNode() const {
        // implement getRootNode here
        // return a pointer to the tree's root node
        return root;
    }

    bool insert(T item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the tree
        if (contains(item)) {
            return false;
        }else {
            return insertHelper(root,item);
        }
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the tree
        return removeHelper(root,item);
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the tree, false otherwise
        return contains(root,item);
    }

    void clear() {
        // implement clear here
        // remove all nodes from the tree
        clearHelper(root);
        root = nullptr;
        _size = 0;
    }

    int size() const {
        // implement size here
        // return the number of nodes in the tree
        return _size;
    }

    void inorder_traversal(std::function<void(T)> visit) const
    {
        return inorderTraversalHelper(root,visit);
    }

    void preorder_traversal(std::function<void(T)> visit) const
    {
        return preOrderTraversalHelper(root,visit);
    }

    void postorder_traversal(std::function<void(T)> visit) const
    {
        return postOrderTraversalHelper(root,visit);
    }
private:
    void inorderTraversalHelper(Node* node, std::function<void(T)> visit) const{
        if (node == nullptr) {
            return;
        }
        inorderTraversalHelper(node->left, visit);
        visit(node->value);
        inorderTraversalHelper(node->right, visit);
    }
    void preOrderTraversalHelper(Node* node, std::function<void(T)> visit) const {
        if (node == nullptr) {
            return;
        }
        visit(node->value);
        preOrderTraversalHelper(node->left, visit);
        preOrderTraversalHelper(node->right, visit);
    }
    void postOrderTraversalHelper(Node* node, std::function<void(T)> visit) const{
        if (node == nullptr) {
            return;
        }
        postOrderTraversalHelper(node->left, visit);
        postOrderTraversalHelper(node->right, visit);
        visit(node->value);
    }
    bool contains(Node* node, T item) const {
        // implement contains here
        // return true if item is in the tree, false otherwise
        if (node == nullptr) {
            return false;
        }
        if (node->value == item) {
            return true;
        }
        if (item < node->value) {
            return contains(node->left,item);
        }else {
            return contains(node->right,item);
        }
    }
    void clearHelper(Node* node) {
        if (node == nullptr) {
            return;
        }
        clearHelper(node->left);
        clearHelper(node->right);
        delete node;
    }
    bool insertHelper(Node*& node, T item) {
        if (node == nullptr) {
            node = new Node(item);
            _size++;
            return true;
        }
        if (node->value == item) {
            return false;
        }
        if (item < node->value) {
            return insertHelper(node->left, item);
        }else {
            return insertHelper(node->right, item);
        }
    }
    Node* get_inorder_predecessor(Node* const& node) {
        // Pass in the node, not the left child
        Node* iop = node->left;
        while (iop->right != nullptr) {
            iop = iop->right;
        }
        return iop;
    }
    bool removeHelper(Node*& node, T value) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == value) {
            if (node->right == nullptr) {
                auto tmp = node;
                node = node->left;
                delete tmp;
                _size--;
            }
            else if (node->left == nullptr) {
                auto tmp = node;
                node = node->right;
                delete tmp;
                _size--;
            }else {
                auto iop = get_inorder_predecessor(node);
                node->value = iop->value;
                return removeHelper(node->left, iop->value);
            }
            return true;
        }else if (value < node->value) {
            return removeHelper(node->left, value);
        }else {
            return removeHelper(node->right, value);
        }
    }
};

