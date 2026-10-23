#ifndef TRIE_H
#define TRIE_H

#include "VisualizerHook.h"
#include <unordered_map>
#include <string>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;
    VisualizerHook& hook;

public:
    Trie(VisualizerHook& vHook);
    void insert(const std::string& word);
    bool search(const std::string& word);
    bool startsWith(const std::string& prefix);
};

#endif