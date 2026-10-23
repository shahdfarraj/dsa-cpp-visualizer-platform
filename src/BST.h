#ifndef BST_H
#define BST_H

#include "VisualizerHook.h"
#include <vector>

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
    void inorderHelper(BSTNode* node, std::vector<int>& out) const;
    void destroy(BSTNode* node);

public:
    explicit BST(VisualizerHook& vHook);
    ~BST();
    BST(const BST&) = delete;
    BST& operator=(const BST&) = delete;

    void insert(int val);
    bool search(int val);
    std::vector<int> inorder() const;   // sorted values (useful for tests)
};

#endif
