/*
Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

https://leetcode.com/problems/clone-graph/
*/

#include <gtest/gtest.h>

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    // clone by bfs
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        queue<Node*> q;
        q.push(node);
        Node* clone = new Node(node->val, {});
        map[node] = clone;

        while (!q.empty()) {
            Node* n = q.front();
            q.pop();

            for (auto ngh : n->neighbors) {
                auto it = map.find(ngh);
                if (it == map.end()) {
                    map[ngh] = new Node(ngh->val, {});
                    q.push(ngh);
                }
                map[n]->neighbors.push_back(map[ngh]);
            }
        }

        return clone;
    }

    // clone by dfs
    Node* cloneGraph_dfs(Node* node) {
        if (node == nullptr) return nullptr;

        if (map.find(node) == map.end()) {
            map[node] = new Node(node->val, {});
            for (Node* adj : node->neighbors) {
                map[node]->neighbors.push_back(cloneGraph_dfs(adj));
            }
        }
        return map[node];
    }

private:
    unordered_map<Node*, Node*> map;
};
