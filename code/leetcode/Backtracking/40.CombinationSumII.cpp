/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

https://leetcode.com/problems/combination-sum-ii/

*/

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSumII(vector<int>& candidates, int target) {
        std::vector<int> curr;
        std::vector<std::vector<int>> res;

        sort(candidates.begin(), candidates.end());
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
            if (index > start && cands[index] == cands[index - 1]) continue;
            curr.push_back(cands[index]);
            helper(cands, target - cands[index], index + 1, curr, res);
            curr.pop_back();
        }
    }
};

TEST(CombinationSumII, Example1) {
    Solution sol;
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = {{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}};
    vector<vector<int>> ret = sol.combinationSumII(nums, target);

    ASSERT_EQ(ret, ans);
}

TEST(CombinationSumII, Example2) {
    Solution sol;
    vector<int> nums = {2, 5, 2, 1, 2};
    int target = 5;
    vector<vector<int>> ans = {{1, 2, 2}, {5}};
    vector<vector<int>> ret = sol.combinationSumII(nums, target);

    ASSERT_EQ(ret, ans);
}
