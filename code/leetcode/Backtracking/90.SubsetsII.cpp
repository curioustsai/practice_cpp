/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
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
        vector<vector<int>> subs;
        vector<int> sub;

        subsets(nums, 0, sub, subs);
        return subs;
    }

    void subsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);

        for (int i = start; i < nums.size(); i++) {
            //prune
            if (i > start && nums[i] == nums[i-1])
                continue;
            sub.push_back(nums[i]);
            subsets(nums, i+1, sub, subs);
            sub.pop_back();
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
