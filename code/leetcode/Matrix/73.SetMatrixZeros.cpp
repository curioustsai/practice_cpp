
/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.
*/

#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    // Space Complexity: O(1);
    // Save states at the first row and first col
    // https://leetcode.com/problems/set-matrix-zeroes/discuss/26014/Any-shorter-O(1)-space-solution
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool bFirstZerosRow = false;
        bool bFirstZerosCol = false;

        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) { bFirstZerosRow = true; }
        }

        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) { bFirstZerosCol = true; }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) { matrix[i][j] = 0; }
            }
        }

        if (bFirstZerosRow) {
            for (int j = 0; j < n; j++) { matrix[0][j] = 0; }
        }

        if (bFirstZerosCol) {
            for (int i = 0; i < n; i++) { matrix[i][0] = 0; }
        }
    }
};

TEST(SetMatrixZeros, Example1) {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> ans = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
}

TEST(SetMatrixZeros, Example2) {
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    vector<vector<int>> ans = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
}
