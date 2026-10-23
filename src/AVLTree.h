#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "VisualizerHook.h"
#include <algorithm>
#include <vector>

struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;
    VisualizerHook& hook;

    int getHeight(AVLNode* node);
    int getBalanceFactor(AVLNode* node);
    void updateHeight(AVLNode* node);

    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);

    AVLNode* insertHelper(AVLNode* node, int val);
    void inorderHelper(AVLNode* node, std::vector<int>& out) const;
    bool isBalancedHelper(AVLNode* node);
    void destroy(AVLNode* node);

public:
    explicit AVLTree(VisualizerHook& vHook);
    ~AVLTree();
    AVLTree(const AVLTree&) = delete;
    AVLTree& operator=(const AVLTree&) = delete;

    void insert(int val);
    bool search(int val);
    std::vector<int> inorder() const;
    int height();
    bool isBalanced();
};

#endif
