/*
 * You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
 * Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
 *
 * 0 <= j <= nums[i] and
 * Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
 * i + j < n
 *
 * https://leetcode.com/problems/jump-game-ii/description/
*/

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int j = 0;
        int result = 0;
        int n = nums.size();

        while (j < n-1) {
            if (j + nums[j] >= n - 1) {
                result++;
                break;
            }
            int maxIndex = j + 1;
            int maxValue = 0;
            for (int i = j; i <= j + nums[j]; i++) {
                if (i + nums[i] > maxValue) {
                    maxIndex = i;
                    maxValue = i + nums[i];
                }
            }
            result++;
            j = maxIndex;
        }
        return result;
    }
};

TEST(JumpGameII, Example1) {
    vector<int> nums={2,3,1,1,4};
    int ans = 2;
    Solution sol;

    ASSERT_EQ(sol.jump(nums), ans);
}

TEST(JumpGameII, Example2) {
    vector<int> nums={2,3,0,1,4};
    int ans = 2;
    Solution sol;

    ASSERT_EQ(sol.jump(nums), ans);
}
