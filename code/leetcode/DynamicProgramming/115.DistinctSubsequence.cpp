/*
 * Given two strings s and t, return the number of distinct subsequences of s which equals t. 
 * The test cases are generated so that the answer fits on a 32-bit signed integer.
 *
 * https://leetcode.com/problems/distinct-subsequences/description/
*/

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size()) return 0;

        return dfs(s, t, 0, 0);
    }

private:
    map<pair<int, int>, int> dp;
    int dfs(string& s, string& t, int i, int j) {
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;

        if (dp.find({i, j}) != dp.end()) return dp[{i, j}];

        if (s[i] == t[j]) {
            // there are 2 choices, (1) only move i (2) move i & j
            dp[{i, j}] = dfs(s, t, i + 1, j + 1) + dfs(s, t, i + 1, j);
        } else {
            dp[{i, j}] = dfs(s, t, i + 1, j);
        }
        return dp[{i, j}];
    }
};

TEST(NumDistinct, Example1) {
    Solution sol;
    string s = "rabbbit";
    string t = "rabbit";
    int ans = 3;

    ASSERT_EQ(sol.numDistinct(s, t), ans);
}

TEST(NumDistinct, Example2) {
    Solution sol;
    string s = "babgbag";
    string t = "bag";
    int ans = 5;

    ASSERT_EQ(sol.numDistinct(s, t), ans);
}
