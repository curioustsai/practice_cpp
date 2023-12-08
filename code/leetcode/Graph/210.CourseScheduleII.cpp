/*
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
 * You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai. 
 * For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1. 
 * Return the ordering of courses you should take to finish all courses.
 * If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
*/


#include <gtest/gtest.h>

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        // build graph
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //calculateIndegree
        for (int i = 0; i < numCourses; i++) {
            for (int v: graph[i]) {
                indegree[v]++;
            }
        }

        // bfs, remove from the leaf
        vector<int> result;
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) {
                q.push(i);
                result.push_back(i);
            }
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int ngh: graph[v]) {
                indegree[ngh]--;
                if (!indegree[ngh]) {
                    q.push(ngh);
                    result.push_back(ngh);
                }
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i]) return {};
        }

        return result;
    }
};
