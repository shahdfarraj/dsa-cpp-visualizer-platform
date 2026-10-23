#ifndef HEAP_H
#define HEAP_H

#include "VisualizerHook.h"
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;
    VisualizerHook& hook;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    MinHeap(VisualizerHook& vHook);
    void insert(int val);
    int extractMin();
};

#endif