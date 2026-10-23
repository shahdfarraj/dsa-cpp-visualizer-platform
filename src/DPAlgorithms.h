#ifndef DP_ALGORITHMS_H
#define DP_ALGORITHMS_H

#include "VisualizerHook.h"
#include <string>
#include <vector>

class DPAlgorithms {
private:
    VisualizerHook& hook;

    long long fibMemoHelper(int n, std::vector<long long>& memo);

public:
    explicit DPAlgorithms(VisualizerHook& vHook);

    // 1. Longest Common Subsequence
    int LCS(const std::string& text1, const std::string& text2);

    // 2. 0/1 Knapsack Problem
    int knapsack(int capacity, const std::vector<int>& weights, const std::vector<int>& values);

    // 3. Fibonacci (n <= 92 so the result fits in long long)
    long long fibonacci(int n);       // bottom-up tabulation
    long long fibonacciMemo(int n);   // top-down memoization
};

#endif
