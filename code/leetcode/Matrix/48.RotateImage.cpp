/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    //https://leetcode.com/problems/rotate-image/discuss/19002/4ms-few-lines-C%2B%2B-code-Rotate-Image-90-degree-for-O(1)-space
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n - 1;
        while (a < b) {
            for (int i = 0; i < (b - a); ++i) {
                swap(matrix[a][a + i], matrix[a + i][b]);
                swap(matrix[a][a + i], matrix[b][b - i]);
                swap(matrix[a][a + i], matrix[b - i][a]);
            }
            ++a;
            --b;
        }
    }

    //https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image
    /*
     * clockwise rotate
     * first reverse up to down, then swap the symmetry 
     * 1 2 3     7 8 9     7 4 1
     * 4 5 6  => 4 5 6  => 8 5 2
     * 7 8 9     1 2 3     9 6 3
    */
    void rotateI(vector<vector<int>> &matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j) swap(matrix[i][j], matrix[j][i]);
        }
    }

    /*
     * anticlockwise rotate
     * first reverse left to right, then swap the symmetry
     * 1 2 3     3 2 1     3 6 9
     * 4 5 6  => 6 5 4  => 2 5 8
     * 7 8 9     9 8 7     1 4 7
    */
    void anti_rotate(vector<vector<int>> &matrix) {
        for (auto vi : matrix) reverse(vi.begin(), vi.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j) swap(matrix[i][j], matrix[j][i]);
        }
    }
};

TEST(RotateMatrix, Example1) {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> ans = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
    sol.rotate(matrix);

    for (int i = 0; i < matrix.size(); i++) { ASSERT_EQ(matrix[i], ans[i]); }
}

TEST(RotateMatrix, Example2) {
    Solution sol;
    vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    vector<vector<int>> ans = {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};

    sol.rotate(matrix);

    for (int i = 0; i < matrix.size(); i++) { ASSERT_EQ(matrix[i], ans[i]); }
}
