/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false

https://leetcode.com/problems/course-schedule/

Detect cycle in a graph
https://www.geeksforgeeks.org/detect-cycle-in-a-graph/

Detect cycle in a undirected graph
https://www.geeksforgeeks.org/detect-cycle-undirected-graph
*/

#include <gtest/gtest.h>

#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> computeIndgrees(vector<vector<int>>& g) {
        vector<int> indegree(g.size(), 0);

        for (auto v : g) {
            for (auto i : v) indegree[i]++;
        }
        return indegree;
    }

    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto v : prerequisites) { graph[v[1]].push_back(v[0]); }

        return graph;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndgrees(g);

        for (int i = 0; i < numCourses; i++) {
            // find those indgree are 0, and remove their connection
            int j = 0;
            while (j < numCourses) {
                if (!degrees[j++]) break;
            }

            if (j == numCourses) return false;

            degrees[j]--;
            for (int v : g[j]) { degrees[v]--; }
        }
        return true;
    }

    bool canFinish_bfs(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g = buildGraph(numCourses, prerequisites);
        vector<int> indegree = computeIndgrees(g);
        queue<int> q;

        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int n : graph[v]) {
                indegree[n]--;
                if (indegree[n] == 0) q.push(n);
            }
        }

        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] != 0) return false;
        }

        return true;
    }

    bool canFinish_dfs(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g = buildGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false);
        vector<bool> rec(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && cyclic(g, visited, rec, i)) { return false; }
        }

        return true;
    }

    bool cyclic(vector<vector<int>>& g, vector<bool>& visited, vector<bool>& rec, int node) {

        if (!visited[node]) {
            visited[node] = true;
            rec[node] = true;

            for (int v : g[node]) {
                if (!visited[v] && cyclic(g, visited, rec, v)) {
                    return true;
                } else if (rec[v]) {
                    return true;
                }
            }
        }

        rec[node] = false;

        return false;
    }

private:
    vector<vector<int>> graph;
};

TEST(CourseSchedule, Example1) {
    Solution sol;
    vector<vector<int>> prerequisites = {{1, 0}};
    ASSERT_EQ(sol.canFinish(2, prerequisites), true);
}

TEST(CourseSchedule, Example2) {
    Solution sol;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    ASSERT_EQ(sol.canFinish(2, prerequisites), false);
}

TEST(CourseSchedule, Example3) {
    Solution sol;
    vector<vector<int>> prerequisites = {{1, 0}};
    ASSERT_EQ(sol.canFinish_dfs(2, prerequisites), true);
}

TEST(CourseSchedule, Example4) {
    Solution sol;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    ASSERT_EQ(sol.canFinish_dfs(2, prerequisites), false);
}
