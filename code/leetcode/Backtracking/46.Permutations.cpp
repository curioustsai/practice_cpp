/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

https://leetcode.com/problems/permutations/
*/

#include <gtest/gtest.h>

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        perm(nums, 0, res);
        return res;
    }

    void perm(vector<int>& nums, int begin, vector<vector<int>>& res) {
        if (begin >= nums.size()) { res.push_back(nums); }

        for (int i = begin; i < nums.size(); i++) {
            swap(nums[i], nums[begin]);
            perm(nums, begin + 1, res);
            swap(nums[begin], nums[i]);
        }
    }
};

TEST(Permute, Example1) {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    vector<vector<int>> ret = sol.permute(nums);

    for (auto r : ret) {
        for (auto v : r) cout << v << " ";
        cout << endl;
    }
}

TEST(Permute, Example2) {
    Solution sol;
    vector<int> nums = {0, 1};
    vector<vector<int>> ans = {{0, 1}, {1, 0}};
    vector<vector<int>> ret = sol.permute(nums);

    for (auto r : ret) {
        for (auto v : r) cout << v << " ";
        cout << endl;
    }
}
