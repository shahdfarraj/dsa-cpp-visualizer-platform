#ifndef GRAPH_H
#define GRAPH_H

#include "VisualizerHook.h"
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <string>

// Structure to represent a weighted edge
struct Edge {
    int to;
    int weight;
};

class Graph {
private:
    int numVertices;
    bool useMatrix;
    std::vector<std::vector<Edge>> adjList;   // Adjacency List Representation
    std::vector<std::vector<int>> adjMatrix;  // Adjacency Matrix Representation (0 = no edge)
    VisualizerHook& hook;

    void checkVertex(int v) const;

public:
    // useMatrix=false skips the V*V matrix (needed for large benchmarks).
    Graph(int vertices, VisualizerHook& vHook, bool useMatrix = true);

    void addEdge(int u, int v, int weight = 1, bool isDirected = false);

    int getNumVertices() const { return numVertices; }
    bool hasEdge(int u, int v) const;
    const std::vector<std::vector<int>>& getAdjMatrix() const { return adjMatrix; }

    // Traversals: return the visit order
    std::vector<int> BFS(int startNode);
    std::vector<int> DFS(int startNode);

    // Shortest paths: return distances (INT_MAX = unreachable)
    std::vector<int> Dijkstra(int startNode);
    std::vector<int> BellmanFord(int startNode, bool* hasNegativeCycle = nullptr);
};

#endif
