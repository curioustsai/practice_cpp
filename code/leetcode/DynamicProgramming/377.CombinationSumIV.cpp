/*
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
The test cases are generated so that the answer can fit in a 32-bit integer.
*/

#include <gtest/gtest.h>

#include <vector>

using namespace std;

//https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int n : nums) {
                if (i >= n) dp[i] += dp[i - n];
            }
        }
        return dp[target];
    }
};

TEST(CombinationSum4, Example1) {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int target = 4;
    int ans = 7;
    ASSERT_EQ(sol.combinationSum4(nums, target), ans);
}

TEST(CombinationSum4, Example3) {
    Solution sol;
    vector<int> nums = {9};
    int target = 3;
    int ans = 0;
    ASSERT_EQ(sol.combinationSum4(nums, target), ans);
}
