#include "include/TestRunner.h"
#include "include/ComplexityProfiler.h"
#include "include/DPAlgorithms.h"
#include "include/VisualizerHook.h"
#include <vector>

int main() {
    // 1. Run Automated Unit Tests
    TestRunner runner;
    runner.runAllTests();

    // 2. Run Complexity Profiler Test
    std::cout << "\n========================================\n";
    std::cout << "        RUNNING COMPLEXITY PROFILER     \n";
    std::cout << "========================================\n";

    VisualizerHook hook;
    ComplexityProfiler profiler;
    DPAlgorithms dp(hook);

    std::vector<int> weights = {2, 3, 4, 5, 6, 7, 8};
    std::vector<int> values = {3, 4, 5, 8, 10, 11, 13};

    profiler.startTimer();
    dp.knapsack(15, weights, values);
    profiler.incrementOperation(weights.size() * 15);
    profiler.logResults("0/1 Knapsack Algorithm");

    return 0;
}