/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

https://leetcode.com/problems/rotting-oranges/
*/
#include <gtest/gtest.h>

#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int step = -1;
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;

        queue<vector<int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        vector<int> dir = {0, 1, 0, -1, 0, 1};
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int x = q.front()[0];
                int y = q.front()[1];
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int new_x = x + dir[i];
                    int new_y = y + dir[i + 1];

                    if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n) continue;

                    if (grid[new_x][new_y] == 1) {
                        grid[new_x][new_y] = 2;
                        q.push({new_x, new_y});
                        fresh--;
                    }
                }
            }
            step++;
        }

        if (fresh > 0) return -1;
        if (step == -1) return 0;
        return step;
    }
};

TEST(RottingOranges, Exmaple1) {
    Solution sol;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int ans = 4;

    ASSERT_EQ(sol.orangesRotting(grid), ans);
}

TEST(RottingOranges, Exmaple2) {
    Solution sol;
    vector<vector<int>> grid = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    int ans = -1;

    ASSERT_EQ(sol.orangesRotting(grid), ans);
}

TEST(RottingOranges, Exmaple3) {
    Solution sol;
    vector<vector<int>> grid = {{0, 2}};
    int ans = 0;

    ASSERT_EQ(sol.orangesRotting(grid), ans);
}
