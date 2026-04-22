#pragma once
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;
template<class T>
class AVL {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;
        int height;

        Node(T v) : left(nullptr), right(nullptr), value(v), height(1) {}
    };

    AVL(): root(nullptr), _size(0) {
        // implement the constructor here

    }

    ~AVL() {
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
        return insertRecursive(root,item);
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the tree
        return removeHelper(root, item);
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the tree, false otherwise
        return containsHelper(root,item);
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
    Node* root;
    int _size;
    int getHeight(Node* node) {
        return node == nullptr ? 0: node-> height;
    }
    void updateHeight(Node*& node) {
        node->height = max(getHeight(node->left),getHeight(node->right)) + 1;
    }
    int balanceValue (Node*& node) {
        return getHeight(node->right) - getHeight(node->left);
    }
    void promoteLeft(Node*& node) {
        Node* tmp = node->left;
        node->left = tmp->right;
        tmp->right = node;
        updateHeight(node);
        node = tmp;
        updateHeight(node);
    }
    void promoteRight(Node*& node) {
        Node* tmp = node->right;
        node->right = tmp->left;
        tmp->left = node;
        updateHeight(node);
        node = tmp;
        updateHeight(tmp);
    }
    void rebalance(Node*& node) {
        int balance = balanceValue(node);
        if (balance < -1) {
            if (balanceValue(node->left) > 0) {
                promoteRight(node->left);
            }
            promoteLeft(node);
        }
        if (balance > 1) {
            if (balanceValue(node->right) < 0) {
                promoteLeft(node->right);
            }
            promoteRight(node);
            }
    }
    bool insertRecursive(Node*& node, T item) {
        if (node == nullptr) {
            node = new Node(item);
            _size++;
            return true;
        }
        if (node->value == item) {
            return false;
        }
        bool inserted;
        if (item < node->value) {
            inserted = insertRecursive(node->left, item);
        } else {
            inserted = insertRecursive(node->right, item);
        }
        if (inserted) {
            updateHeight(node);
            rebalance(node);
        }
        return inserted;
    }
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
    bool containsHelper(Node* node, T item) const {
        if (node == nullptr) {
            return false;
        }
        if (node -> value == item) {
            return true;
        }
        if (item < node->value) {
            return containsHelper(node->left, item);
        } else {
            return containsHelper(node->right, item);
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
    bool removeHelper(Node*&node, T value) {
        bool removed = false;
        if (node == nullptr) {
            return false;
        }
        if (value < node->value) {
            removed = removeHelper(node->left, value);
        } else if (value > node->value) {
            removed = removeHelper(node->right, value);
        } else { // value == node->value
            removed = true;
            if (!node->left) {
                Node* tmp = node;
                node = node->right;
                delete tmp;
                _size--;
            } else if (!node->right) {
                Node* tmp = node;
                node = node->left;
                delete tmp;
                _size--;
            } else {
                Node* iop = get_inorder_predecessor(node);
                node->value = iop->value;
                removed = removeHelper(node->left, iop->value);
            }
        }
        if (node) {
            updateHeight(node);
            rebalance(node);
        }
        return removed;
    }
    void clearHelper(Node* node) {
        if (node == nullptr) {
            return;
        }
        clearHelper(node->left);
        clearHelper(node->right);
        delete node;
    }
};
