#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
A subarray is a contiguous subsequence of the array.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int maxPos = ans;
        int maxNeg = ans;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) { swap(maxPos, maxNeg); }
            maxPos = max(nums[i], maxPos * nums[i]);
            maxNeg = min(nums[i], maxNeg * nums[i]);
            ans = max(ans, maxPos);
        }
        return ans;
    }
};

TEST(MaxProduct, Test1) {
    Solution sol;
    vector<int> nums = {2, 3, -2, 4};
    int ans = 6;
    ASSERT_EQ(sol.maxProduct(nums), ans);
}

TEST(MaxProduct, Test2) {
    Solution sol;
    vector<int> nums = {-2, 0, -1};
    int ans = 0;
    ASSERT_EQ(sol.maxProduct(nums), ans);
}
