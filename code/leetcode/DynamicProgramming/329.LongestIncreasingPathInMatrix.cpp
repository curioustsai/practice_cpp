/*
* Given an m x n integers matrix, return the length of the longest increasing path in matrix. 
* From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
*
* https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
*/

#include <gtest/gtest.h>

#include <vector>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int result = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                result = max(result, dfs(matrix, i, j, -1));
            }
        }
        return result;
    }

private:
    map<pair<int, int>, int> dp;
    int dfs(vector<vector<int>>& matrix, int i, int j, int prev) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] <= prev)
            return 0;

        if (dp.find({i, j}) != dp.end()) return dp[{i, j}];
        int result = 1;
        result = max(result, 1 + dfs(matrix, i + 1, j, matrix[i][j]));
        result = max(result, 1 + dfs(matrix, i, j + 1, matrix[i][j]));
        result = max(result, 1 + dfs(matrix, i - 1, j, matrix[i][j]));
        result = max(result, 1 + dfs(matrix, i, j - 1, matrix[i][j]));
        dp[{i, j}] = result;
        return result;
    }
};

TEST(LongestIncreasingPath, Example1) {
    Solution sol;
    vector<vector<int>> matrix =  {{9,9,4},{6,6,8},{2,1,1}};
    int ans = 4;

    ASSERT_EQ(sol.longestIncreasingPath(matrix), ans);
}

TEST(LongestIncreasingPath, Example2) {
    Solution sol;
    vector<vector<int>> matrix =  {{3,4,5},{3,2,6},{2,2,1}};
    int ans = 4;

    ASSERT_EQ(sol.longestIncreasingPath(matrix), ans);
}

TEST(LongestIncreasingPath, Example3) {
    Solution sol;
    vector<vector<int>> matrix =  {{1}};
    int ans = 1;

    ASSERT_EQ(sol.longestIncreasingPath(matrix), ans);
}
