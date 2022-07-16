/* 
 Write a program to print connected components in an undirected graph
*/
#include <gtest/gtest.h>

#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    Graph(int v) : V(v) { adj.resize(v); }; // Constructor
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    };
    void connectedComponents() {
        vector<bool> visited(V, false);

        for (int v = 0; v < V; v++) {
            if (visited[v] == false) {
                DFSUtil(v, visited);
                cout << "\n";
            }
        }
    };

private:
    int V;
    vector<vector<int>> adj;
    void DFSUtil(int v, vector<bool>& visited) {

        visited[v] = true;
        cout << v << " ";

        for (int i : adj[v])
            if (!visited[i]) DFSUtil(i, visited);
    };
};

TEST(connectedComponents, Example1) {
    // Create a graph given in the above diagram
    Graph g(5); // 5 vertices numbered from 0 to 4
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Following are connected components \n";
    g.connectedComponents();
}
