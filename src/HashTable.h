#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "VisualizerHook.h"
#include <vector>
#include <list>
#include <string>

// 1. Hash Table using Separate Chaining
class HashTableChaining {
private:
    int capacity;
    int count;
    std::vector<std::list<int>> table;
    VisualizerHook& hook;

    int hashFunction(int key) const {
        int h = key % capacity;
        return h < 0 ? h + capacity : h;   // safe for negative keys
    }

public:
    HashTableChaining(int size, VisualizerHook& vHook);
    void insert(int key);
    bool search(int key);
    int size() const { return count; }
};

// 2. Hash Table using Open Addressing (Linear Probing)
class HashTableOpenAddressing {
private:
    int capacity;
    int count;
    std::vector<int> table;
    std::vector<bool> occupied;
    VisualizerHook& hook;

    int hashFunction(int key) const {
        int h = key % capacity;
        return h < 0 ? h + capacity : h;
    }

public:
    HashTableOpenAddressing(int size, VisualizerHook& vHook);
    void insert(int key);
    bool search(int key);
    int size() const { return count; }
};

#endif
