/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

https://leetcode.com/problems/sort-colors/

https://leetcode.com/problems/sort-colors/discuss/26474/Sharing-C%2B%2B-solution-with-Good-Explanation
*/

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, mid = 0, h = nums.size() - 1;
        while (mid <= h)
            if (nums[mid] == 0)
                swap(nums[mid++], nums[l++]);
            else if (nums[mid] == 1)
                mid++;
            else
                swap(nums[mid], nums[h--]);
    }
};

TEST(SortColors, Example1) {
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    vector<int> ans = {0, 0, 1, 1, 2, 2};

    sol.sortColors(nums);
    ASSERT_EQ(nums, ans);
}

TEST(SortColors, Example2) {
    Solution sol;
    vector<int> nums = {2, 0, 1};
    vector<int> ans = {0, 1, 2};
    sol.sortColors(nums);

    ASSERT_EQ(nums, ans);
}
