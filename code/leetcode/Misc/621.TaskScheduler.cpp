/*
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task.
Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array),
that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.

https://leetcode.com/problems/task-scheduler/
*/

#include <gtest/gtest.h>

#include <unordered_map>

using namespace std;

class Solution {
public:
    // method 1
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        int count = 0;
        for (auto c : tasks) {
            m[c]++;
            count = max(m[c], count);
        }
        int ans = (count - 1) * (n + 1);
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == count) ans++;
        }

        ans = max((int)tasks.size(), ans);

        return ans;
    }
};

TEST(TaskScheduler, Example1) {
    Solution sol;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    int ans = 8;
    ASSERT_EQ(sol.leastInterval(tasks, n), ans);
}

TEST(TaskScheduler, Example2) {
    Solution sol;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 0;
    int ans = 6;
    ASSERT_EQ(sol.leastInterval(tasks, n), ans);
}

TEST(TaskScheduler, Example3) {
    Solution sol;
    vector<char> tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int n = 2;
    int ans = 16;
    ASSERT_EQ(sol.leastInterval(tasks, n), ans);
}
