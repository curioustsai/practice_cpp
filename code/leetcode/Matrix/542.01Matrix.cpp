/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

https://leetcode.com/problems/01-matrix/
*/

#include <gtest/gtest.h>

#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    //https://leetcode.com/problems/01-matrix/discuss/1369741/C%2B%2BJavaPython-BFS-DP-solutions-with-Picture-Clean-and-Concise-O(1)-Space
    vector<vector<int>> updateMatrix_bfs(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<vector<int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (auto d : dirs) {
                int nx = p[0] + d[0];
                int ny = p[1] + d[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || mat[nx][ny] != -1) continue;
                mat[nx][ny] = mat[p[0]][p[1]] + 1;
                q.push({nx, ny});
            }
        }
        return mat;
    }

    // dp
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), INF = m + n; // The distance of cells is up to (M+N)
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] == 0) continue;
                int top = INF, left = INF;
                if (r - 1 >= 0) top = mat[r - 1][c];
                if (c - 1 >= 0) left = mat[r][c - 1];
                mat[r][c] = min(top, left) + 1;
            }
        }
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (mat[r][c] == 0) continue;
                int bottom = INF, right = INF;
                if (r + 1 < m) bottom = mat[r + 1][c];
                if (c + 1 < n) right = mat[r][c + 1];
                mat[r][c] = min(mat[r][c], min(bottom, right) + 1);
            }
        }
        return mat;
    }
};

TEST(Matrix01, Example1) {
    vector<vector<int>> mat;
    mat.push_back({0, 0, 0});
    mat.push_back({0, 1, 0});
    mat.push_back({0, 0, 0});

    vector<vector<int>> ans;
    ans.push_back({0, 0, 0});
    ans.push_back({0, 1, 0});
    ans.push_back({0, 0, 0});

    Solution sol;
    ASSERT_EQ(sol.updateMatrix(mat), ans);
}

TEST(Matrix01, Example2) {
    vector<vector<int>> mat;
    mat.push_back({0, 0, 0});
    mat.push_back({0, 1, 0});
    mat.push_back({1, 1, 1});

    vector<vector<int>> ans;
    ans.push_back({0, 0, 0});
    ans.push_back({0, 1, 0});
    ans.push_back({1, 2, 1});

    Solution sol;
    ASSERT_EQ(sol.updateMatrix(mat), ans);
}
