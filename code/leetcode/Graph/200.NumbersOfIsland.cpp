/*
https://leetcode.com/problems/number-of-islands/
*/
#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) { count += countIsland(grid, i, j); }
        }

        return count;
    }

    int countIsland(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return 0;

        if (grid[x][y] == '0') return 0;

        grid[x][y] = '0';
        countIsland(grid, x + 1, y);
        countIsland(grid, x, y + 1);
        countIsland(grid, x - 1, y);
        countIsland(grid, x, y - 1);

        return 1;
    }
};

TEST(NumIsland, Example1) {
    Solution sol;
    vector<vector<char>> grid;
    grid.push_back({'1', '1', '1', '1', '0'});
    grid.push_back({'1', '1', '0', '1', '0'});
    grid.push_back({'1', '1', '0', '0', '0'});
    grid.push_back({'0', '0', '0', '0', '0'});

    int ans = 1;

    ASSERT_EQ(sol.numIslands(grid), ans);
}

TEST(NumIsland, Example2) {
    Solution sol;
    vector<vector<char>> grid;
    grid.push_back({'1', '1', '0', '0', '0'});
    grid.push_back({'1', '1', '0', '0', '0'});
    grid.push_back({'0', '0', '1', '0', '0'});
    grid.push_back({'0', '0', '0', '1', '1'});

    int ans = 3;

    ASSERT_EQ(sol.numIslands(grid), ans);
}
