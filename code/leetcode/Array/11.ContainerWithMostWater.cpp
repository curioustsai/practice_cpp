#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i])

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int>& nums) {
        int max_area = 0;
        for (int left = 0; left < nums.size() - 1; left++) {
            for (int right = left + 1; right < nums.size(); right++) {
                int area = std::min(nums[left], nums[right]) * (right - left);
                max_area = std::max(max_area, area);
            }
        }
        return max_area;
    }
};

TEST(ContainerWithMaximumWater, Test1) {
    Solution sol;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int ans = 49;

    ASSERT_EQ(sol.maxArea(height), ans);
}

TEST(ContainerWithMaximumWater, Test2) {
    Solution sol;
    vector<int> height = {1, 1};
    int ans = 1;

    ASSERT_EQ(sol.maxArea(height), ans);
}
