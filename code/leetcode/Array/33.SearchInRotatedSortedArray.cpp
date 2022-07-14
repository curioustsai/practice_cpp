/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Solution
https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/2196530/C%2B%2B-MOST-INTUITIVE-APPROACH-w-VISUAL-and-BREAKDOWN-O(log(n))

*/
#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;

            if (nums[left] <= nums[mid]) {
                // case 1.1 middle in the left subarray
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // case 1.2 middle in the right subarray
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

TEST(SearchInRotatedArray, Test1) {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int ans = 4;

    ASSERT_EQ(sol.search(nums, target), ans);
}

TEST(SearchInRotatedArray, Test2) {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 3;
    int ans = -1;

    ASSERT_EQ(sol.search(nums, target), ans);
}

TEST(SearchInRotatedArray, Test3) {
    Solution sol;
    vector<int> nums = {1};
    int target = 0;
    int ans = -1;

    ASSERT_EQ(sol.search(nums, target), ans);
}
