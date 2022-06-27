/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.
*/

#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    // O(log n), binary search variation
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return nums[left];
    }
};

TEST(Rotated, minimum1) {
    Solution sol;
    vector<int> vec = {3, 4, 5, 1, 2};
    int ans = 1;
}
TEST(Rotated, minimum2) {
    Solution sol;
    vector<int> vec = {4, 5, 6, 7, 0, 1, 2};
    int ans = 0;
}
TEST(Rotated, minimum3) {
    Solution sol;
    vector<int> vec = {11, 13, 15, 17};
    int ans = 11;
}
