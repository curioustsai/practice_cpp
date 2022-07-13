#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int m = heights.size();
        int n = heights[0].size();

        if (m == 0 || n == 0) return res;

        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<bool>> pacific(m, vector<bool>(n, false));

        // use backtrace to reduce computation
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }

        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (pacific[i][j] && atlantic[i][j]) { res.push_back({i, j}); };
            }
        }

        return res;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y) {
        int m = heights.size();
        int n = heights[0].size();

        visited[x][y] = true;
        if (x - 1 >= 0 && heights[x][y] <= heights[x - 1][y] && !visited[x - 1][y])
            dfs(heights, visited, x - 1, y);
        if (y - 1 >= 0 && heights[x][y] <= heights[x][y - 1] && !visited[x][y - 1])
            dfs(heights, visited, x, y - 1);
        if (x + 1 < m && heights[x][y] <= heights[x + 1][y] && !visited[x + 1][y])
            dfs(heights, visited, x + 1, y);
        if (y + 1 < n && heights[x][y] <= heights[x][y + 1] && !visited[x][y + 1])
            dfs(heights, visited, x, y + 1);
    }
};

TEST(PacificAtlantic, Example1) {
    Solution sol;
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};

    vector<vector<int>> result = sol.pacificAtlantic(heights);
    vector<vector<int>> ans = {{0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}};

    sort(result.begin(), result.end(),
         [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

    ASSERT_EQ(result, ans);
}

TEST(PacificAtlantic, Example2) {
    Solution sol;
    vector<vector<int>> heights = {{2, 1}, {1, 2}};

    vector<vector<int>> result = sol.pacificAtlantic(heights);
    vector<vector<int>> ans = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

    sort(result.begin(), result.end(),
         [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

    ASSERT_EQ(result, ans);
}

TEST(PacificAtlantic, Example3) {
    Solution sol;
    vector<vector<int>> heights = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};

    vector<vector<int>> result = sol.pacificAtlantic(heights);
    vector<vector<int>> ans = {{0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};

    sort(result.begin(), result.end(),
         [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

    ASSERT_EQ(result, ans);
}
