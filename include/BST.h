#ifndef BST_H
#define BST_H

#include "VisualizerHook.h"

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    
    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    BSTNode* root;
    VisualizerHook& hook;

    BSTNode* insertHelper(BSTNode* node, int val);
    bool searchHelper(BSTNode* node, int val);

public:
    BST(VisualizerHook& vHook);
    void insert(int val);
    bool search(int val);
};

#endif