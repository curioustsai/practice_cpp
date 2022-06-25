// TODO:
// Dijkstra algorithm
// A* algorithm
#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int n) : num_nodes(n) {
        edge = new int*[num_nodes];
        for (int i = 0; i < num_nodes; i++) { edge[i] = new int[num_nodes]{0}; }
    };
    ~Graph() {
        for (int i = 0; i < num_nodes; i++) { delete[] edge[i]; }
        delete[] edge;
    }

    void Connect(int u, int v, int dist) { edge[u][v] = edge[v][u] = dist; }
    void Display() {
        for (int i = 0; i < num_nodes; i++) {
            for (int j = 0; j < num_nodes; j++) { cout << edge[i][j] << " "; }
            cout << endl;
        }
    }

    int** GetEdge() const { return edge; }

    // FIMXE: work for unidirectional, but bi-directional?
    void BFS(int start) {
        vector<bool> visited(num_nodes, false);
        queue<int> q;

        q.push(start);
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            visited[n] = true;
            cout << n << " ";

            for (int i = 0; i < num_nodes; i++) {
                if (visited[i] == false && edge[n][i] != 0) q.push(i);
            }
        }
        cout << endl;
    }

    vector<int> Dijkstra(int start) {
        vector<bool> visited(num_nodes, false);
        vector<int> dist(num_nodes, INT32_MAX);
        visited[start] = true;
        dist[start] = 0;

        for (int count = 0; count < num_nodes - 1; count++) {
            int u = minDist(dist, visited);
            visited[u] = true;

            // visit every v and check if our minDist u can shorten distance of v
            for (int v = 0; v < num_nodes; v++) {
                if (!visited[v] && edge[u][v] && dist[u] != INT32_MAX &&
                    (dist[u] + edge[u][v] < dist[v]))
                    dist[v] = dist[u] + edge[u][v];
            }
        }
        // print solution
        for (auto d : dist) { cout << d << endl; }

        return dist;
    }

private:
    int minDist(vector<int> dist, vector<bool> visited) {
        int min_index = 0;
        int min_dist = INT32_MAX;

        for (int n = 0; n < num_nodes; n++) {
            if (!visited[n] && dist[n] < min_dist) {
                min_dist = dist[n];
                min_index = n;
            }
        }

        return min_index;
    }
    int num_nodes{0};
    int** edge{nullptr};
};

class GraphTest : public testing::Test {
protected:
    void SetUp() override {
        // https://www.geeksforgeeks.org/wp-content/uploads/Fig-11.jpg
        graph = new Graph(9);
        graph->Connect(0, 1, 4);
        graph->Connect(0, 7, 8);
        graph->Connect(1, 7, 11);
        graph->Connect(1, 2, 8);
        graph->Connect(7, 8, 7);
        graph->Connect(7, 6, 1);
        graph->Connect(2, 3, 7);
        graph->Connect(2, 5, 4);
        graph->Connect(2, 8, 2);
        graph->Connect(8, 6, 6);
        graph->Connect(6, 5, 2);
        graph->Connect(3, 5, 14);
        graph->Connect(3, 4, 9);
        graph->Connect(5, 4, 10);
    }

    void TearDown() override { delete graph; }

    Graph* graph;
};

TEST_F(GraphTest, Connect) {
    int ans[9][9] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},  {4, 0, 8, 0, 0, 0, 0, 11, 0}, {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0}, {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},  {8, 11, 0, 0, 0, 0, 1, 0, 7}, {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    graph->Display();

    int** e = graph->GetEdge();

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) { ASSERT_EQ(ans[i][j], e[i][j]); }
    }
}

TEST_F(GraphTest, BFS) { graph->BFS(0); }

TEST_F(GraphTest, Dijkstra) {
    // https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7
    vector<int> ans = {0, 4, 12, 19, 21, 11, 9, 8, 14};
    vector<int> shortestPath = graph->Dijkstra(0);
    for (int i = 0; i < ans.size(); i++) ASSERT_EQ(ans[i], shortestPath[i]);
}
