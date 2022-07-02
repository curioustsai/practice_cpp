/*
Given an m x n matrix, return all elements of the matrix in spiral order.
*/

#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    // https://leetcode.com/problems/spiral-matrix/discuss/20573/A-concise-C%2B%2B-implementation-based-on-Directions
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = matrix.size();
        int n = matrix[0].size();

        if (m == 0 || n == 0) return res;

        int idir = 0;
        vector<int> nSteps = {n, m - 1};

        int irow = 0, icol = -1;
        while (nSteps[idir % 2]) {
            for (int i = 0; i < nSteps[idir % 2]; i++) {
                irow += dirs[idir][0];
                icol += dirs[idir][1];

                res.push_back(matrix[irow][icol]);
            }
            nSteps[idir % 2]--;
            idir = (idir + 1) % 4;
        }
        return res;
    }
};

TEST(SprialOrder, Example1) {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = {1, 2, 3, 6, 9, 8, 7, 4, 5};

    ASSERT_EQ(sol.spiralOrder(matrix), ans);
}

TEST(SprialOrder, Example2) {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> ans = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};

    ASSERT_EQ(sol.spiralOrder(matrix), ans);
}
