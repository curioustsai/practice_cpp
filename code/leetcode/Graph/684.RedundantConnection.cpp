/*
*
* In this problem, a tree is an undirected graph that is connected and has no cycles.
* You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added.
* The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.
* The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
* Return an edge that can be removed so that the resulting graph is a tree of n nodes.
* If there are multiple answers, return the answer that occurs last in the input.
*
* https://leetcode.com/problems/redundant-connection/description/
*/

#include <gtest/gtest.h>

using namespace std;
/*
    Given undirected graph, return an edge that can be removed to make a tree
    Ex. edges = [[1,2],[1,3],[2,3]] -> [2,3]

    If n nodes & n edges, guaranteed a cycle
    How to know creating cycle? When connecting a node already connected
    Union Find: can find this redundant edge, track parents & ranks

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> rank(n + 1, 1);
        vector<int> result;

        for (int i = 1; i <= n; i++) { parent[i] = i; }

        for (int i = 0; i < edges.size(); i++) {
            int m = edges[i][0];
            int n = edges[i][1];

            if (!doUnion(parent, rank, m, n)) {
                result = {m, n};
                break;
            }
        }
        return result;
    }

private:
    int findParent(vector<int>& parent, int p) {
        int pp = parent[p];
        while (pp != p) {
            p = pp;
            pp = parent[p];
        }
        return pp;
    }

    bool doUnion(vector<int>& parent, vector<int>& rank, int m, int n) {
        int p1 = findParent(parent, m);
        int p2 = findParent(parent, n);

        if (p1 == p2) return false;

        if (rank[p1] >= rank[p2]) {
            parent[p2] = p1;
            rank[p1] += p2;
        } else {
            parent[p1] = p2;
            rank[p2] += p1;
        }
        return true;
    }
};
