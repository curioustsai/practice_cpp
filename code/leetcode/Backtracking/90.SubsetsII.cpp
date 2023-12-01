/*
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
 
https://leetcode.com/problems/subsets-ii/
*/
#include <gtest/gtest.h>

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;

        dfs(nums, 0, cur, res);
        return res;
    }

    void dfs(vector<int>& nums, int start, vector<int>& cur, vector<vector<int>>& res) {
        res.push_back(cur);

        for (int i = start; i < nums.size(); i++) {
            //prune
            if (i > start && nums[i] == nums[i-1])
                continue;
            cur.push_back(nums[i]);
            dfs(nums, i+1, cur, res);
            cur.pop_back();
        }
    }
};

TEST(Subsets, Example1) {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = {{}, {1}, {2}, {1, 2}, {2, 2}, {1, 2, 2}};

    sol.subsetsWithDup(nums);
}

TEST(Subsets, Example2) {
    Solution sol;
    vector<int> nums = {0};
    vector<vector<int>> ans = {{}, {0}};

    sol.subsetsWithDup(nums);
}
