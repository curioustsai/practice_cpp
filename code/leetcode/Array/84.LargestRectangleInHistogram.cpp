/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

https://leetcode.com/problems/largest-rectangle-in-histogram/

https://abhinandandubey.github.io/posts/2019/12/15/Largest-Rectangle-In-Histogram.html
*/
#include <gtest/gtest.h>

#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> height) {
        int n = height.size();
        if (n == 0) return 0;
        if (n == 1) return height[0];

        height.push_back(0);
        n++;

        int ans = 0;
        stack<int> s;
        int i = 0, j = 0, h = 0;
        while (i < n) {
            if (s.empty() || height[i] > height[s.top()]) {
                s.push(i++);
            } else {
                h = height[s.top()];
                s.pop();
                j = s.empty() ? -1 : s.top();
                ans = max(ans, h * (i - j - 1));
            }
        }
        return ans;
    }
};

TEST(LargestRectangleArea, Example1) {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int output = 10;

    ASSERT_EQ(sol.largestRectangleArea(heights), output);
}

TEST(LargestRectangleArea, Example2) {
    Solution sol;
    vector<int> heights = {2, 4};
    int output = 4;

    ASSERT_EQ(sol.largestRectangleArea(heights), output);
}
