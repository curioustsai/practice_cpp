/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.
*/
#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Time complexity: O(n^2)
    int maxSubArray_bruteforce(vector<int>& nums) {
        int cur_sum = 0;
        int max_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                cur_sum += nums[j];
                max_sum = max(max_sum, cur_sum);
            }
        }
        return max_sum;
    }

    // Time complexity: O(n)
    int maxSubArray(vector<int>& nums) {
        int curr_sum = nums[0];
        int max_sum = curr_sum;

        for (int i = 1; i < nums.size(); i++) {
            curr_sum = max(curr_sum + nums[i], nums[i]);
            max_sum = max(curr_sum, max_sum);
        }

        return max_sum;
    }

    // Follow up question, show the subarray, index
    int maxSubArrayIndex(vector<int>& nums) {
        int curr_sum = nums[0];
        int max_sum = curr_sum;
        int start = 0, end = 0, s = 0;

        for (int i = 1; i < nums.size(); i++) {
            curr_sum = curr_sum + nums[i];
            if (curr_sum < nums[i]) {
                s = i;
                curr_sum = nums[i];
            }

            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                start = s;
                end = i;
            }
        }

        cout << "start: " << start << " end: " << end << endl;

        return max_sum;
    }
};

TEST(MaxSubArray, Test1) {
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = 6;
    ASSERT_EQ(sol.maxSubArray(nums), 6);
}

TEST(MaxSubArray, Test2) {
    Solution sol;
    vector<int> nums = {1};
    int ans = 1;
    ASSERT_EQ(sol.maxSubArray(nums), 1);
}

TEST(MaxSubArray, Test3) {
    Solution sol;
    vector<int> nums = {5, 4, -1, 7, 8};
    int ans = 23;
    ASSERT_EQ(sol.maxSubArray(nums), 23);
}
