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
    Graph(int n) : num_nodes(n) { adjacent = new vector<int>[num_nodes]; };
    ~Graph() { delete[] adjacent; }

    void connect(int from, int to) { adjacent[from].push_back(to); };
    bool isRoute(int from, int to) {
        // Breadwith first search
        queue<int> que;
        vector<bool> visited(num_nodes);

        que.push(from);
        while (!que.empty()) {
            int start = que.front();
            visited[start] = true;
            que.pop();
            for (int e : adjacent[start]) {
                if (e == to) return true;
                if (!visited[e]) que.push(e);
            }
        }
        return false;
    }

    void BFS(int from) {
        queue<int> q;
        vector<bool> visited(num_nodes, false);
        q.push(from);

        while (!q.empty()) {
            int s = q.front();
            cout << s << endl;
            visited[s] = true;

            q.pop();

            for (int e : adjacent[s]) {
                if (!visited[e]) { q.push(e); }
            }
        }
    }

    void DFS(int from) {
        vector<bool> visited(num_nodes, false);

        for (int adj : adjacent[from]) {
            visited[adj] = true;
            cout << adj << endl;
            DFS(adj);
        }
    }

private:
    int num_nodes;
    vector<int>* adjacent;
};

class GraphTest : public testing::Test {
protected:
    void SetUp() override {
        /*
         * Test graph :
         * 0 <---4----> 1
         * ^            ^
         * |            |
         * |            |
         * 5---->2----> 3
         */
        graph = new Graph(6);
        graph->connect(5, 2);
        graph->connect(5, 0);
        graph->connect(4, 0);
        graph->connect(4, 1);
        graph->connect(2, 3);
        graph->connect(3, 1);
    }

    void TearDown() override {}

    Graph* graph;
};

TEST_F(GraphTest, Routing) {
    ASSERT_EQ(graph->isRoute(5, 4), false);
    ASSERT_EQ(graph->isRoute(5, 1), true);
}

TEST_F(GraphTest, BFS) { graph->BFS(5); }
TEST_F(GraphTest, DFS) { graph->DFS(5); }
