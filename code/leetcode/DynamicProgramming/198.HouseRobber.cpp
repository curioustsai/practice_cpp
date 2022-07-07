/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected 
and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

#include <gtest/gtest.h>

#include <vector>

using namespace std;

//https://leetcode.com/problems/house-robber/

class Solution {
public:
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
