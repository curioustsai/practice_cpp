/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

https://leetcode.com/problems/partition-equal-subset-sum/

https://leetcode.com/problems/partition-equal-subset-sum/discuss/1624939/C%2B%2BPython-5-Simple-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP-to-Bitmask
*/

#include <gtest/gtest.h>

#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum & 1) return false;

        vector<vector<int>> dp(201, vector<int>(10001, -1));
        return subsetSum(nums, totalSum / 2, 0, dp);
    }

    bool subsetSum(vector<int>& nums, int sum, int i, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        if (i >= nums.size() || sum < 0) return false;
        if (dp[i][sum] != -1) return dp[i][sum];

        dp[i][sum] = subsetSum(nums, sum - nums[i], i + 1, dp) || subsetSum(nums, sum, i + 1, dp);

        return dp[i][sum];
    }
};

TEST(CanPartition, Example1) {
    Solution sol;
    vector<int> nums = {1, 5, 11, 5};
    bool ans = true;
    ASSERT_EQ(sol.canPartition(nums), ans);
}

TEST(CanPartition, Example2) {
    Solution sol;
    vector<int> nums = {1, 2, 3, 5};
    bool ans = false;
    ASSERT_EQ(sol.canPartition(nums), ans);
}
