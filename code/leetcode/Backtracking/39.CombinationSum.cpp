/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target.
You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times.
Two combinations are unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

https://leetcode.com/problems/combination-sum/description/

*/

#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<int> curr;
        std::vector<std::vector<int>> res;

        helper(candidates, target, 0, curr, res);
        return res;
    }

private:
    void helper(std::vector<int>& cands, int target, int start, std::vector<int>& curr,
                std::vector<std::vector<int>>& res) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        if (start >= cands.size() || target < 0) return;

        for (int index = start; index < cands.size(); index++) {
            curr.push_back(cands[index]);
            helper(cands, target - cands[index], index, curr, res);
            curr.pop_back();
        }
    }

    void helper2(std::vector<int>& cands, int target, int start, std::vector<int>& curr,
                 std::vector<std::vector<int>>& res) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        if (start >= cands.size() || target < 0) return;

        curr.push_back(cands[start]);
        helper(cands, target - cands[start], start, curr, res);
        curr.pop_back();
        helper(cands, target, start + 1, curr, res);
    }
};

TEST(CombinationSum, Example1) {
    Solution sol;
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> ans = {{2, 2, 3}, {7}};
    vector<vector<int>> ret = sol.combinationSum(nums, target);

    ASSERT_EQ(ret, ans);
}

TEST(CombinationSum, Example2) {
    Solution sol;
    vector<int> nums = {2, 3, 5};
    int target = 8;
    vector<vector<int>> ans = {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}};
    vector<vector<int>> ret = sol.combinationSum(nums, target);

    ASSERT_EQ(ret, ans);
}
