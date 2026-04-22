#pragma once

struct Node {
    Node* left;
    Node* right;
    int value;

    Node(int v) : left(nullptr), right(nullptr), value(v) {}
};

bool find(Node* root, int item) {
    // implement find here
    // return true if item is in the subtree, false otherwise
    //test 1 on an empty tree (root is nullptr)
    if (root == nullptr) {
        return false;
    }
    //test 2 on a tree with a single right child
    if (root->value == item) {
        return true; // found the item
    }
    //test 4 on a tree that is balanced (includes) left and right
    if (item < root->value) {
        return find(root->left, item);
    }else {
        return find(root->right, item);
    }

}
