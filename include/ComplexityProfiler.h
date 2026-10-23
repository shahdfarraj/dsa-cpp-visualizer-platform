#ifndef COMPLEXITY_PROFILER_H
#define COMPLEXITY_PROFILER_H

#include <chrono>
#include <iostream>
#include <string>

class ComplexityProfiler {
private:
    std::chrono::high_resolution_clock::time_point startTime;
    long long operationCount;

public:
    ComplexityProfiler();
    void startTimer();
    long long stopTimer();
    void incrementOperation(long long count = 1);
    void resetOperations();
    long long getOperations() const;
    void logResults(const std::string& algorithmName);
};

#endif