#pragma once
#include <algorithm>
#include <iostream>
using namespace std;
struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

// Hint: you might find it helpful to write an update_height function that takes
// a Node* and updates its height field based on the heights of its children
int height(Node* node) {
    if (node == nullptr) {
        return 0;
    }else {
        return node->height;
    }
}
void updateHeight(Node* node) {
    if (node != nullptr) {
        node->height = 1 + max(height(node->left),height(node->right));
    }
}
void promote_left(Node*& root) {
    // implement promote_left here
    auto newRoot = root->left;
    root->left = root->left->right;
    newRoot->right = root;
    updateHeight(root);
    root = newRoot;
    updateHeight(newRoot);

}

void promote_right(Node*& root) {
    // implement promote_right here
    auto newRoot = root->right;
    root->right = root->right->left;
    newRoot->left = root;
    updateHeight(root);
    root = newRoot;
    updateHeight(newRoot);
}

void rebalance(Node*& root) {
    // implement rebalance here
    //Right-Right and Right-Left Case
    if (height(root->right) - height(root->left) > 1) {
        if (height(root->right->left) - height(root->right->right) > 0) {
            promote_left(root->right);
        }
        promote_right(root);
    }
    //Left-Left and Left-Right Case
    if (height(root->right) - height(root->left) < -1) {
        if (height(root->left->right) - height(root->left->left) > 0) {
            promote_right(root->left);
        }
        promote_left(root);
    }
}
