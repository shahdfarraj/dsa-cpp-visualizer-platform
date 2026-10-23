#ifndef VISUALIZER_HOOK_H
#define VISUALIZER_HOOK_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstddef>

class ComplexityProfiler;

class VisualizerHook {
private:
    std::ofstream logFile;
    bool isFirstEntry;
    bool enabled;          // false = no console, no file (for benchmarks)
    bool consoleOutput;    // false = file only
    std::size_t stepCount;
    ComplexityProfiler* profiler;  // optional: every step counts as 1 operation

    static std::string escapeJson(const std::string& s);

public:
    // Pass "" as filename to disable file logging completely.
    explicit VisualizerHook(const std::string& filename = "steps.json");
    ~VisualizerHook();

    VisualizerHook(const VisualizerHook&) = delete;
    VisualizerHook& operator=(const VisualizerHook&) = delete;

    void recordStep(const std::string& action, int value);

    void setEnabled(bool on);
    bool isEnabled() const;
    void setConsoleOutput(bool on);
    void attachProfiler(ComplexityProfiler* p);
    std::size_t getStepCount() const;
    void resetStepCount();
};

#endif
