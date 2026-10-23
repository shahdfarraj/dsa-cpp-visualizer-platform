# Extensible C++ Backend Platform for DSA Visualization & Educational Research

An open-source C++ framework engineered to instrument Data Structures and Algorithms (DSA), output execution trace records (`steps.json`), profile microsecond computational performance, and run automated unit tests.

## 🚀 Key Features

* **Complete DSA Coverage**: Trees (BST, AVL, Min-Heap, Trie), Graphs (BFS, DFS, Dijkstra, Bellman-Ford), Hashing (Chaining, Linear Probing), and Dynamic Programming (LCS, 0/1 Knapsack).
* **Automated Judge**: Multi-module unit testing framework (`TestRunner`) with 100% pass verification (11/11 tests).
* **Complexity Profiler**: High-precision operational cycle and runtime calculation using `std::chrono`.
* **Visualizer Hooks**: Automatic logging of execution mutations exported to JSON for frontend animation (`index.html`).

## 🛠️ Build & Run Instructions

### 1. Compile C++ Backend Engine
```bash
g++ -Iinclude main.cpp src/*.cpp -o main