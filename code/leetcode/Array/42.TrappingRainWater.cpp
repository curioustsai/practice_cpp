/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

https://leetcode.com/problems/trapping-rain-water/
*/

#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 2) return 0;
        int n = height.size();

        int left = 0, right = n - 1;
        int max_left = 0, max_right = 0;
        int ans = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= max_left)
                    max_left = height[left];
                else
                    ans += max_left - height[left];
                left++;
            } else {
                if (height[right] >= max_right)
                    max_right = height[right];
                else
                    ans += max_right - height[right];
                right--;
            }
        }
        return ans;
    }
};

TEST(TrapRainWater, Test1) {
    Solution sol;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int ans = 6;

    ASSERT_EQ(sol.trap(height), ans);
}

TEST(ContainerWithMaximumWater, Test2) {
    Solution sol;
    vector<int> height = {1, 4, 2, 0, 3, 2, 5};
    int ans = 9;

    ASSERT_EQ(sol.trap(height), ans);
}
