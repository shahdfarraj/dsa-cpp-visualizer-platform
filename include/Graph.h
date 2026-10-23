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
    std::vector<std::vector<Edge>> adjList; // Adjacency List Representation
    std::vector<std::vector<int>> adjMatrix; // Adjacency Matrix Representation
    VisualizerHook& hook;

public:
    Graph(int vertices, VisualizerHook& vHook);

    void addEdge(int u, int v, int weight = 1, bool isDirected = false);
    
    // Traversals
    void BFS(int startNode);
    void DFS(int startNode);

    // Shortest Path Algorithms
    void Dijkstra(int startNode);
    void BellmanFord(int startNode);
};

#endif