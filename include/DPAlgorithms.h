#ifndef DP_ALGORITHMS_H
#define DP_ALGORITHMS_H

#include "VisualizerHook.h"
#include <string>
#include <vector>

class DPAlgorithms {
private:
    VisualizerHook& hook;

public:
    DPAlgorithms(VisualizerHook& vHook);

    // 1. Longest Common Subsequence
    int LCS(const std::string& text1, const std::string& text2);

    // 2. 0/1 Knapsack Problem
    int knapsack(int capacity, const std::vector<int>& weights, const std::vector<int>& values);
};

#endif