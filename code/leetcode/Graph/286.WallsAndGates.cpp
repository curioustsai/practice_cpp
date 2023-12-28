/*
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

*/

#include <gtest/gtest.h>

#include <queue>

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> q;
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[0].size(); j++) {
                if (rooms[i][j] == 0) { q.push({i, j}); }
            }
        }

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < dirs.size(); i++) {
                int xx = x + dirs[i][0];
                int yy = y + dirs[i][1];

                if (xx < 0 || xx >= rooms.size() || yy < 0 || yy >= rooms[0].size() ||
                    rooms[xx][yy] != INT32_MAX)
                    continue;

                rooms[xx][yy] = rooms[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }

private:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
};
