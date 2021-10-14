#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class Graph {
public:
    Graph(int numNodes): numNodes(numNodes) { adj = new vector<int>[numNodes]; }
    ~Graph() { delete[] adj; }

    void connect(int from, int to) { adj[from].push_back(to); }
    bool isRoute(int from, int to) {
        queue<int> que;
        vector<bool> visited(numNodes, false);

        que.push(from);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            // arrive the destination
            if (p == to) { return true; }
            visited[p] = true;
            // push adj points
            for (auto& i : adj[p]) {
                if (!visited[i]) que.push(i);
            }
        }

        return false;
    };

private:
    vector<int>* adj;
    int numNodes;
};

int main(void) {
    /*
	 * Test graph : 
	 * 0 <---4---->1
	 * ^ 			^
	 * |			|
	 * |			|
     * 5---->2---->3 
     */

    Graph* graph = new Graph(6);
    graph->connect(5, 2);
    graph->connect(5, 0);
    graph->connect(4, 0);
    graph->connect(4, 1);
    graph->connect(2, 3);
    graph->connect(3, 1);

    cout << graph->isRoute(5, 4) << endl; // false
    cout << graph->isRoute(5, 1) << endl; // true

    return 0;
}
