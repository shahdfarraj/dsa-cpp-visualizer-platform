#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include "VisualizerHook.h"
#include "ComplexityProfiler.h"
#include "BST.h"
#include "AVLTree.h"
#include "Heap.h"
#include "Trie.h"
#include "HashTable.h"
#include "Graph.h"
#include "DPAlgorithms.h"
#include <iostream>
#include <string>

class TestRunner {
private:
    int passedTests;
    int totalTests;
    VisualizerHook hook;

    void assertTest(const std::string& testName, bool condition);

public:
    TestRunner();
    void runAllTests();
    void testTrees();
    void testHashing();
    void testGraphs();
    void testDP();
    void testProfiler();
    bool allPassed() const { return passedTests == totalTests; }
};

#endif
