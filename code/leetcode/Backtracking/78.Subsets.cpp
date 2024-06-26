/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

https://leetcode.com/problems/subsets/submissions/

https://leetcode.com/problems/subsets/discuss/27278/C%2B%2B-RecursiveIterativeBit-Manipulation
*/
#include <gtest/gtest.h>

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;

        subsets(nums, 0, sub, subs);
        return subs;
    }

    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }
};

TEST(Subsets, Example1) {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = {{}, {1}, {2}, {3}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}};

    sol.subsets(nums);
}
