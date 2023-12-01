/*
  Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

  Each row must contain the digits 1-9 without repetition.
  Each column must contain the digits 1-9 without repetition.
  Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

  Note:
    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.

  https://leetcode.com/problems/valid-sudoku/description/
*/

#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int blocks[3][3][9] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int number = board[r][c] - '0' - 1; // map num 1-9 to 0-index

                    if (rows[r][number]++) return 0;
                    if (cols[c][number]++) return 0;
                    if (blocks[r/3][c/3][number]++) return 0;

                }
            }
        }
        return 1;
    }
};
