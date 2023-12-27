/*
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
 *
 * https://leetcode.com/problems/n-queens/
 *
*/

#include <gtest/gtest.h>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;
        backtrack(n, 0, result, board);

        return result;
    }

private:
    set<int> cols;
    set<int> negDiag;
    set<int> posDiag;

    void backtrack(int n, int row, vector<vector<string>>& result, vector<string>& board) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols.find(col) != cols.end() ||
                negDiag.find(row-col) != negDiag.end() ||
                posDiag.find(row+col) != posDiag.end())
                continue;

            cols.insert(col);
            negDiag.insert(row - col);
            posDiag.insert(row + col);
            board[row][col] = 'Q';

            backtrack(n, row + 1, result, board);

            cols.erase(col);
            negDiag.erase(row - col);
            posDiag.erase(row + col);
            board[row][col] = '.';
        }
    }
};

TEST(NQueens, Example1) {
    Solution sol;
    int n = 4;
    vector<vector<string>> ans = {{".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."}};

    ASSERT_EQ(sol.solveNQueens(n), ans);
}

TEST(NQueens, Example2) {
    Solution sol;
    int n = 1;
    vector<vector<string>> ans = {{"Q"}};

    ASSERT_EQ(sol.solveNQueens(n), ans);
}
