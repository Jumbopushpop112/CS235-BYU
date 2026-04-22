#pragma once
#include <cstdlib>
#include <functional>


template <typename T>
class BST
{
public:
    //create a node structure and make intial constructor
    struct Node {
        T value;
        Node* left;
        Node* right;
        Node(T v): left(nullptr), right(nullptr), value(v) {}
    };
    size_t _size;
    Node* root;
    BST(): root(nullptr), _size(0) {}

    ~BST()
    {
        //deconstruct (clear) the tree
        clear();
    }
    void destroyTree(Node* node) {
        if (node == nullptr) {
            return;
        }
        destroyTree(node->left);
        destroyTree(node->right);
    }
    bool insert(T const &value)
    {
        return insertHelper(root, value);
    }

    bool contains(T const &value)
    {
        return containsHelper(root, value);
    }

    bool remove(T const &value)
    {
        return removeHelper(root, value);
    }

    void inorder_traversal(std::function<void(T)> visit) const
    {
        return inOrderHelper(root, visit);
    }

    void preorder_traversal(std::function<void(T)> visit) const
    {
        return preOrderHelper(root, visit);
    }

    void postorder_traversal(std::function<void(T)> visit) const
    {
        return postOrderHelper(root, visit);
    }

    size_t size() const
    {
        return _size;
    }

    void clear()
    {
        clearHelper(root);
        _size = 0;
        root = nullptr;

    }
private:

    void inOrderHelper(Node* node, std::function<void(T)> visit) const{
        if (node == nullptr) {
            return;
        }
        inOrderHelper(node->left, visit);
        visit(node->value);
        inOrderHelper(node->right, visit);
    }
    void preOrderHelper(Node* node, std::function<void(T)> visit) const{
        if (node == nullptr) {
            return;
        }
        visit(node->value);
        preOrderHelper(node->left, visit);
        preOrderHelper(node->right, visit);
    }
    void postOrderHelper(Node* node, std::function<void(T)> visit) const{
        if (node == nullptr) {
            return;
        }
        postOrderHelper(node->left, visit);
        postOrderHelper(node->right, visit);
        visit(node->value);
    }
    Node* get_inorder_predecesor(Node* const& node) {
        auto iop = node->left;
        while (iop->right != nullptr) {
            iop = iop->right;
        }
        return iop;
    }
    bool removeHelper(Node*& node, T const &value) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == value) {
            if (node->left == nullptr) {
                auto tmp = node;
                node = node->right;
                delete tmp;
                _size--;
            }
            else if (node->right == nullptr) {
                auto tmp = node;
                node = node->left;
                delete tmp;
                _size--;
            }
            else {
                auto iop = get_inorder_predecesor(node);
                node->value = iop->value;
                return removeHelper(node->left, iop->value);
            }
            return true;
        }
        else if (value < node->value){
            return removeHelper(node->left, value);
        }else {
            return removeHelper(node->right, value);
        }
    }
    bool containsHelper(Node* node, T const &value){
        //base case followed by if we found the value, last two cases help us know which side to check
        if (node == nullptr) {
            return false;
        }
        if (node->value == value) {
            return true;
        }
        if (value < node->value) {
            return containsHelper(node->left, value);
        }else {
            return containsHelper(node->right, value);
        }
    }
    void clearHelper(Node* node) {
        if (node == nullptr) {
            return;
        }
        //loop through the each side of the tree and delete the nodes
        clearHelper(node->left);
        clearHelper(node->right);
        delete node;
    }
    bool insertHelper(Node*& node, T const &item){
        //if nothing is in there, make it the head, if the value is already in there, we can't insert, and the last two checks help us know where to insert it

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
};
