/*
* You are given an integer array nums and an integer target.
* You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
*
* For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
* Return the number of different expressions that you can build, which evaluates to target.
*
* https://leetcode.com/problems/target-sum/description/
*/

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0, 0);
    }

private:
    map<pair<int, int>, int> dp;
    int dfs(vector<int>& nums, int target, int i, int sum) {
        if (i == nums.size())
            return (sum == target) ? 1:0;

        if (dp.find({i, sum}) != dp.end())
            return dp[{i, sum}];

        dp[{i, sum}] = dfs(nums, target, i + 1, sum + nums[i]) +
            dfs(nums, target, i + 1, sum - nums[i]);

        return dp[{i, sum}];   
    }
};
