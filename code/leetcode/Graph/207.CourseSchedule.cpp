/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false
*/

#include <gtest/gtest.h>

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

    bool canFinish_dfs(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g = buildGraph(numCourses, prerequisites);
        vector<bool> tovisit(numCourses, false);
        vector<bool> visited(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && !acyclic(g, tovisit, visited, i)) { return false; }
        }

        return true;
    }

    bool acyclic(vector<vector<int>>& g, vector<bool>& tovisit, vector<bool>& visited, int node) {
        // not visited && to be visited, good.
        // clean node, impossible to be cyclic, return false directly
        if (tovisit[node]) return false;

        // not visited at first but visited back, definitely a cyclic, return true
        if (visited[node]) return true;

        tovisit[node] = visited[node] = true;

        for (int v : g[node]) {
            if (!acyclic(g, tovisit, visited, v)) { return false; }
        }
        tovisit[node] = false;

        return true;
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
