#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "VisualizerHook.h"
#include <algorithm>

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

public:
    AVLTree(VisualizerHook& vHook);
    void insert(int val);
};

#endif