#ifndef HEAP_H
#define HEAP_H

#include "VisualizerHook.h"
#include <vector>
#include <optional>
#include <cstddef>

class MinHeap {
private:
    std::vector<int> heap;
    VisualizerHook& hook;

    static std::size_t parent(std::size_t i) { return (i - 1) / 2; }
    static std::size_t leftChild(std::size_t i) { return (2 * i) + 1; }
    static std::size_t rightChild(std::size_t i) { return (2 * i) + 2; }

    void heapifyUp(std::size_t index);
    void heapifyDown(std::size_t index);

public:
    explicit MinHeap(VisualizerHook& vHook);
    void insert(int val);
    std::optional<int> extractMin();   // std::nullopt when the heap is empty
    std::optional<int> peek() const;
    std::size_t size() const;
    bool empty() const;
};

#endif
