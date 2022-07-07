/*
You are given an integer array nums. You are initially positioned at the array's first index,
and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.
*/

/*
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/

#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    // https://leetcode.com/problems/jump-game/discuss/20917/Linear-and-simple-solution-in-C%2B%2B
    bool canJump(vector<int>& nums) {
        int n = nums.size(), farest = 0;
        for (int i = 0; i < n; i++) {
            if (farest < i) return false;
            farest = max(i + nums[i], farest);
        }
        return true;
    }
};

TEST(UniquePaths, Example1) {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    bool ans = true;
    ASSERT_EQ(sol.canJump(nums), ans);
}

TEST(UniquePaths, Example2) {
    Solution sol;
    vector<int> nums = {3, 2, 1, 0, 4};
    bool ans = false;
    ASSERT_EQ(sol.canJump(nums), ans);
}
