/*
Write a function that returns true if a given undirected graph is tree and false otherwise.
For example, the following graph is a tree

https://www.geeksforgeeks.org/check-given-graph-tree/

check if a given graph is tree or not
1. acyclic
2. all connected
*/

#include <gtest/gtest.h>

#include <iostream>
#include <vector>
using namespace std;

// Class for an undirected graph
class Graph {
public:
    Graph(int v) : V(v) { adj.resize(v); };
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    };

    bool isTree() {
        vector<bool> visited(V, false);

        // The call to isCyclicUtil serves multiple purposes.
        // It returns true if graph reachable from vertex 0
        // is cyclic. It also marks all vertices reachable
        // from 0.
        if (isCyclicUtil(0, visited, -1)) return false;

        // If we find a vertex which is not reachable from 0
        // (not marked by isCyclicUtil(), then we return false
        for (int u = 0; u < V; u++)
            if (!visited[u]) return false;

        return true;
    }

    bool isCyclicUtil(int v, vector<bool>& visited, int parent) {
        visited[v] = true;

        // Recur for all the vertices adjacent to this vertex
        vector<int>::iterator i;
        for (int i : adj[v]) {
            // If an adjacent is not visited, then recur for
            // that adjacent
            if (!visited[i]) {
                if (isCyclicUtil(i, visited, v)) return true;
            }

            // If an adjacent is visited and not parent of current
            // vertex, then there is a cycle.
            else if (i != parent)
                return true;
        }
        return false;
    }

private:
    int V;                   // No. of vertices
    vector<vector<int>> adj; // Pointer to an array for adjacency lists
};

TEST(GraphTree, Example1) {
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    ASSERT_EQ(g1.isTree(), true);
}

TEST(GraphTree, Example2) {
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    ASSERT_EQ(g2.isTree(), false);
}
