/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

https://leetcode.com/problems/house-robber-ii/
*/

#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> v1(nums.begin(), nums.end() - 1);
        vector<int> v2(nums.begin() + 1, nums.end());
        return max(rob_(v1), rob_(v2));
    }

private:
    int rob_(vector<int>& nums) {
        vector<int> money(nums.size() + 1, 0);
        money[0] = 0;
        money[1] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            money[i + 1] = max(money[i], money[i - 1] + nums[i]);
        }

        return money[nums.size()];
    }
};

TEST(HouseRobber, Example1) {
    Solution sol;
    vector<int> nums = {2, 3, 2};
    int ans = 3;
    ASSERT_EQ(sol.rob(nums), ans);
}

TEST(HouseRobber, Example2) {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    int ans = 4;
    ASSERT_EQ(sol.rob(nums), ans);
}
