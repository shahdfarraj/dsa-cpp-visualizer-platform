#ifndef VISUALIZER_HOOK_H
#define VISUALIZER_HOOK_H

#include <string>
#include <iostream>
#include <fstream>

class VisualizerHook {
private:
    std::ofstream logFile;
    bool isFirstEntry;

public:
    VisualizerHook();  // Constructor
    ~VisualizerHook(); // Destructor

    void recordStep(const std::string& action, int value);
};

#endif