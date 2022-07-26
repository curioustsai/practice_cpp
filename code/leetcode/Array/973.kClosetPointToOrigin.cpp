/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

https://leetcode.com/problems/k-closest-points-to-origin/
*/

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        partial_sort(points.begin(), points.begin() + k, points.end(),
                     [](const vector<int>& a, const vector<int>& b) {
                         return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
                     });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

TEST(kCloset, Example1) {
    Solution sol;
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    int k = 1;
    vector<vector<int>> ans = {{-2, 2}};

    ASSERT_EQ(sol.kClosest(points, k), ans);
}

TEST(kCloset, Example2) {
    Solution sol;
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;
    vector<vector<int>> ans = {{3, 3}, {-2, 4}};

    ASSERT_EQ(sol.kClosest(points, k), ans);
}
