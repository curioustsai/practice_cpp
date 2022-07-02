#include <gtest/gtest.h>

#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (search(board, i, j, word.c_str())) { return true; }
            }
        }
        return false;
    }

private:
    bool search(vector<vector<char>>& board, int r, int c, const char* word) {
        if (!word[0]) { return true; }
        int m = board.size(), n = board[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[0]) { return false; }
        board[r][c] = 0;
        if (search(board, r - 1, c, word + 1) || search(board, r + 1, c, word + 1) ||
            search(board, r, c - 1, word + 1) || search(board, r, c + 1, word + 1)) {
            return true;
        }
        board[r][c] = word[0];
        return false;
    }
};

TEST(WordSearch, Example1) {
    Solution sol;
    vector<vector<char>> board = {{'a', 'b', 'c', 'e'}, {'s', 'f', 'c', 's'}, {'a', 'd', 'e', 'e'}};
    string word = "abcced";
    ASSERT_EQ(sol.exist(board, word), true);
}

TEST(WordSearch, Example2) {
    Solution sol;
    vector<vector<char>> board = {{'a', 'b', 'c', 'e'}, {'s', 'f', 'c', 's'}, {'a', 'd', 'e', 'e'}};
    string word = "see";
    ASSERT_EQ(sol.exist(board, word), true);
}

TEST(WordSearch, Example3) {
    Solution sol;
    vector<vector<char>> board = {{'a', 'b', 'c', 'e'}, {'s', 'f', 'c', 's'}, {'a', 'd', 'e', 'e'}};
    string word = "abcb";
    ASSERT_EQ(sol.exist(board, word), false);
}
