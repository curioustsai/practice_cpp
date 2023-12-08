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
    int largestRectangleArea_BruteForce(vector<int> heights) {
        int n = heights.size();
        int maxArea = 0;
        
        for (int i = 0; i < n; i++) {
            int minHeight = INT_MAX;
            for (int j = i; j < n; j++) {
                minHeight = min(minHeight, heights[j]);
                maxArea = max(maxArea, minHeight * (j - i + 1));
            }
        }
        
        return maxArea;
    }

    int largestRectangleArea(vector<int> height) {
        int n = height.size();
        if (n == 0) return 0;
        if (n == 1) return height[0];

        height.push_back(0);
        n++;

        int ans = 0;
        stack<int> s;
        int i = 0, j = 0, h = 0;

        // Monotonic increasing stack, if curr height lower extend back, find max area
        while (i < n) {
            if (s.empty() || height[i] > height[s.top()]) {
                s.push(i++);
            } else {
                h = height[s.top()];
                s.pop();
                // because of Monotonic stack, the second heighest must be the boundary
                // width = (right: i - 1 ) - (left: j + 1) + 1 = i - 1 - j - 1 + 1 = i - j - 1
                j = s.empty() ? -1 : s.top();
                ans = max(ans, h * (i - j - 1));
            }
        }
        return ans;
    }

    int largestRectangleArea2(vector<int>& heights) {
        // pair: [index, height]
        stack<pair<int, int>> stk;
        int result = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            
            while (!stk.empty() && stk.top().second > heights[i]) {
                int index = stk.top().first;
                int width = i - index;
                int height = stk.top().second;
                stk.pop();
                
                result = max(result, height * width);
                start = index;
            }
            
            stk.push({start, heights[i]});
        }
        
        while (!stk.empty()) {
            int width = heights.size() - stk.top().first;
            int height = stk.top().second;
            stk.pop();
            
            result = max(result, height * width);
        }
                          
        return result;
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
