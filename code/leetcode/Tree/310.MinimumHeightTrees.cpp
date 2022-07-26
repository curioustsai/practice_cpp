/*
A tree is an undirected graph in which any two vertices are connected by exactly one path.
In other words, any connected graph without simple cycles is a tree.
Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges 
where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree,
you can choose any node of the tree as the root.

When you select a node x as the root, the result tree has height h. Among all possible rooted trees,
those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
Return a list of all MHTs' root labels. You can return the answer in any order.
The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

https://leetcode.com/problems/minimum-height-trees/
*/

#include <gtest/gtest.h>

#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    // topo sort
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0), ans;
        queue<int> q;
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) {
                q.push(i);
                indegree[i]--;
            }
        }

        while (!q.empty()) {
            ans.clear();
            int size = q.size();
            while (size--) {
                int cur = q.front();
                q.pop();
                ans.push_back(cur);

                for (auto v : graph[cur]) {
                    indegree[v]--;
                    if (indegree[v] == 1) q.push(v);
                }
            }
        }
        //If only 1 node in the graph, the min height is 0, with root being '0'
        if (n == 1) ans.push_back(0);
        return ans;
    }
};

TEST(MinHeightTree, Example1) {
    Solution sol;
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    int n = 4;
    vector<int> output = {1};

    ASSERT_EQ(sol.findMinHeightTrees(n, edges), output);
}
