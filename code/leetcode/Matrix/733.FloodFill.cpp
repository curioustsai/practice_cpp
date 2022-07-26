/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel,
plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
Return the modified image after performing the flood fill.

https://leetcode.com/problems/flood-fill/
*/
#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
    void dfs(vector<vector<int>>& image, int i, int j, int val, int color) {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] != val ||
            image[i][j] == color) {
            return;
        }
        image[i][j] = color;
        dfs(image, i + 1, j, val, color);
        dfs(image, i - 1, j, val, color);
        dfs(image, i, j + 1, val, color);
        dfs(image, i, j - 1, val, color);
    }
};

TEST(FloodFill, Example1) {
    vector<vector<int>> image;
    image.push_back({1, 1, 1});
    image.push_back({1, 1, 0});
    image.push_back({1, 0, 1});

    vector<vector<int>> ans;
    ans.push_back({2, 2, 2});
    ans.push_back({2, 2, 0});
    ans.push_back({2, 0, 1});

    Solution sol;
    ASSERT_EQ(sol.floodFill(image, 1, 1, 2), ans);
}

TEST(FloodFill, Example2) {
    vector<vector<int>> image;
    image.push_back({0, 0, 0});
    image.push_back({0, 0, 0});

    vector<vector<int>> ans;
    ans.push_back({0, 0, 0});
    ans.push_back({0, 0, 0});

    Solution sol;
    ASSERT_EQ(sol.floodFill(image, 0, 0, 0), ans);
}
