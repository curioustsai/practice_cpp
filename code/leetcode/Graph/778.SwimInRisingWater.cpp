/*
 * You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
 * The rain starts to fall. At time t, the depth of the water everywhere is t.
 * You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t.
 * You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
 * Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).
 *
 * https://leetcode.com/problems/swim-in-rising-water/description/
*/

#include <gtest/gtest.h>

#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) { return 0; }

        vector<vector<bool>> visited(n, vector<bool>(n));
        visited[0][0] = true;

        int result = max(grid[0][0], grid[n - 1][n - 1]);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({result, 0, 0});

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            result = max(result, curr[0]);

            for (int i = 0; i < 4; i++) {
                int x = curr[1] + dirs[i][0];
                int y = curr[2] + dirs[i][1];

                if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y]) { continue; }

                if (x == n - 1 && y == n - 1) { return result; }

                pq.push({grid[x][y], x, y});
                visited[x][y] = true;
            }
        }

        return -1;
    }

private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};

TEST(SwimInWater, Example1) {
    vector<vector<int>> grid = {{0, 2}, {1, 3}};
    int ans = 3;
    Solution sol;
    ASSERT_EQ(sol.swimInWater(grid), ans);
}

TEST(SwimInWater, Example2) {
    vector<vector<int>> grid = {{0, 1, 2, 3, 4},
                                {24, 23, 22, 21, 5},
                                {12, 13, 14, 15, 16},
                                {11, 17, 18, 19, 20},
                                {10, 9, 8, 7, 6}};
    int ans = 16;
    Solution sol;
    ASSERT_EQ(sol.swimInWater(grid), ans);
}
