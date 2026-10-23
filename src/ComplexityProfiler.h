#ifndef COMPLEXITY_PROFILER_H
#define COMPLEXITY_PROFILER_H

#include <chrono>
#include <iostream>
#include <string>

class ComplexityProfiler {
private:
    std::chrono::steady_clock::time_point startTime;
    long long operationCount;
    long long lastDuration;   // microseconds of the last stopTimer()
    bool running;

public:
    ComplexityProfiler();
    void startTimer();
    long long stopTimer();                 // returns microseconds (0 if timer not started)
    long long getLastDuration() const;
    void incrementOperation(long long count = 1);
    void resetOperations();
    long long getOperations() const;
    void logResults(const std::string& algorithmName);
};

#endif
