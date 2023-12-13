/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.

https://leetcode.com/problems/min-cost-climbing-stairs/
*/

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }

        return min(dp[n-1], dp[n-2]);
    }
};

TEST(MinCostClimbingStairs, Example1)
{
    vector<int> cost = {10, 15, 20};
    int ans = 15;
    Solution sol;

    ASSERT_EQ(sol.minCostClimbingStairs(cost), 15);
}

TEST(MinCostClimbingStairs, Example2)
{
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    int ans = 6;
    Solution sol;

    ASSERT_EQ(sol.minCostClimbingStairs(cost), 6);
}
