/*
https://leetcode.com/problems/word-search-ii/

Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once in a word.
*/

#include <algorithm>
#include <gtest/gtest.h>
#include <string>

using namespace std;

struct Node {
    bool isEnd;
    Node* child[26];

    Node() {
        isEnd = false;
        for (int i = 0; i < 26; i++) child[i] = nullptr;
    }

    Node(bool end) : isEnd(end) {
        for (int i = 0; i < 26; i++) child[i] = nullptr;
    }
};

class WordDictionary {
public:
    WordDictionary() {}
    ~WordDictionary() {}

    void addWord(string word) {
        Node* ptr = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (ptr->child[index] == nullptr) { ptr->child[index] = new Node; }
            ptr = ptr->child[index];
        }
        ptr->isEnd = true;
    }

    Node* getRoot() { return root; }

private:
    Node* root = new Node();
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        WordDictionary wd;
        vector<string> res;
        for (string& s : words) wd.addWord(s);

        int m = board.size();
        int n = board[0].size();
        Node* root = wd.getRoot();
        string word = "";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) { dfs(board, i, j, root, word, res); }
        }

        return res;
    }

    void dfs(vector<vector<char>>& board, int i, int j, Node* root, string word,
             vector<string>& res) {
        if (i < 0 || i > board.size() || j < 0 || j > board[0].size() || board[i][j] == '#') return;
        char c = board[i][j];
        if (root->child[c - 'a'] == nullptr) return;

        word = word + c;
        root = root->child[c - 'a'];
        if (root->isEnd) res.push_back(word);

        board[i][j] = '#';
        dfs(board, i + 1, j, root, word, res);
        dfs(board, i, j + 1, root, word, res);
        dfs(board, i - 1, j, root, word, res);
        dfs(board, i, j - 1, root, word, res);
        board[i][j] = c;
    }
};

TEST(WordSearchII, Example1) {
    Solution sol;
    vector<vector<char>> board;
    board.push_back({'o', 'a', 'a', 'n'});
    board.push_back({'e', 't', 'a', 'e'});
    board.push_back({'i', 'h', 'k', 'r'});
    board.push_back({'i', 'f', 'l', 'v'});

    vector<string> word = {"oath", "pea", "eat", "rain"};
    vector<string> ans = {"eat", "oath"};
    vector<string> res = sol.findWords(board, word);
    sort(res.begin(), res.end(), [](string a, string b) { return a[0] < b[0]; });

    ASSERT_EQ(res, ans);
}

TEST(WordSearchII, Example2) {
    Solution sol;
    vector<vector<char>> board2(2, vector<char>(2, 0));
    board2.push_back({'a', 'b'});
    board2.push_back({'c', 'd'});

    vector<string> word = {"abcd"};
    vector<string> ans = {};
    vector<string> res = sol.findWords(board2, word);
    sort(res.begin(), res.end(), [](string a, string b) { return a[0] < b[0]; });

    ASSERT_EQ(res, ans);
}
