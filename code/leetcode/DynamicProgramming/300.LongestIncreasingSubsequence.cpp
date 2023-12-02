/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.
A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements.
For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

https://leetcode.com/problems/longest-increasing-subsequence/
*/

#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    //Time O(n^2)
    //Space O(n)
    int lengthOfLIS(vector<int>& nums) {
        int res = 1;
        vector<int> dp(nums.size(), 1); // reocrd the LIS at each index

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) { dp[i] = max(dp[i], dp[j] + 1); }
            }
            res = max(res, dp[i]);
        }

        return res;
    };
};

TEST(LongestIncreasingSubsequence, ExampleI) {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int ans = 4;

    ASSERT_EQ(sol.lengthOfLIS(nums), ans);
}

TEST(LongestIncreasingSubsequence, ExampleII) {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 2, 3};
    int ans = 4;

    ASSERT_EQ(sol.lengthOfLIS(nums), ans);
}

TEST(LongestIncreasingSubsequence, ExampleIII) {
    Solution sol;
    vector<int> nums = {7, 7, 7, 7, 7, 7, 7};
    int ans = 1;

    ASSERT_EQ(sol.lengthOfLIS(nums), ans);
}
