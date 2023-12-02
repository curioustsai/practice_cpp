/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected 
and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

https://leetcode.com/problems/house-robber/
*/

#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    // Time complexity: O(2^n)
    int rob_bruteForce(vector<int>& nums) {
        return helper(nums, nums.size() - 1); 
    }

    int helper(vector<int>& nums, int index) {
        if (index == 0) return nums[0];
        else if (index == 1) return max(nums[0], nums[1]);
        return max(helper(nums, index - 2) + nums[index], helper(nums, index - 1));
    }
    //https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.
    int rob(vector<int>& nums) {
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
    vector<int> nums = {1, 2, 3, 1};
    int ans = 4;
    ASSERT_EQ(sol.rob(nums), ans);
}

TEST(HouseRobber, Example2) {
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    int ans = 12;
    ASSERT_EQ(sol.rob(nums), ans);
}
