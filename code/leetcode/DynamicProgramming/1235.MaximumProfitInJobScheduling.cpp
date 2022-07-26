/*
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.
If you choose a job that ends at time X you will be able to start another job that starts at time X.

https://leetcode.com/problems/maximum-profit-in-job-scheduling/
https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409009/JavaC%2B%2BPython-DP-Solution

further reading
Unweighted Interval Scheduling
Weighted Interval Scheduling
https://www.geeksforgeeks.org/weighted-job-scheduling/
*/

#include <gtest/gtest.h>

#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) { jobs.push_back({endTime[i], startTime[i], profit[i]}); }
        sort(jobs.begin(), jobs.end());

        // keep {endtime, profit}
        map<int, int> dp{{0, 0}};
        for (auto& job : jobs) {
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second) { dp[job[0]] = cur; }
        }
        return dp.rbegin()->second;
    }
};

TEST(JobScheduling, Example1) {
    Solution sol;
    vector<int> startTime = {1, 2, 3, 3};
    vector<int> endTime = {3, 4, 5, 6};
    vector<int> profit = {50, 10, 40, 70};
    int output = 120;

    ASSERT_EQ(sol.jobScheduling(startTime, endTime, profit), output);
}

TEST(JobScheduling, Example2) {
    Solution sol;
    vector<int> startTime = {1, 2, 3, 4, 6};
    vector<int> endTime = {3, 5, 10, 6, 9};
    vector<int> profit = {20, 20, 100, 70, 60};
    int output = 150;

    ASSERT_EQ(sol.jobScheduling(startTime, endTime, profit), output);
}

TEST(JobScheduling, Example3) {
    Solution sol;
    vector<int> startTime = {1, 1, 1};
    vector<int> endTime = {2, 3, 4};
    vector<int> profit = {5, 6, 4};
    int output = 6;

    ASSERT_EQ(sol.jobScheduling(startTime, endTime, profit), output);
}
