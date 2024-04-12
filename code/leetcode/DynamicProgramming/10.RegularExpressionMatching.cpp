/*
 * Given an input string s and a pattern p, implement regular expression
 * matching with support for '.' and '*' where:
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 */

#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) { return dfs(s, p, 0, 0); }

private:
    map<pair<int, int>, bool> dp;
    bool dfs(string s, string p, int i, int j) {
        if (i >= s.size() && j >= p.size()) return true;
        if (j >= p.size()) return false;

        if (dp.find({i, j}) != dp.end()) return dp[{i, j}];
        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.size() && p[j + 1] == '*') {
            // choices: either (1) don't use *, or (2) use *
            dp[{i, j}] = dfs(s, p, i, j + 2) || (match && dfs(s, p, i + 1, j));
            return dp[{i, j}];
        }

        return dp[{i, j}] = (match) ? dfs(s, p, i + 1, j + 1) : false;
    }
};

TEST(IsMatch, Example1) {
    Solution sol;
    string s = "aa";
    string p = "a";

    bool ans = false;
    ASSERT_EQ(sol.isMatch(s, p), ans);
}

TEST(IsMatch, Example2) {
    Solution sol;
    string s = "aa";
    string p = "a*";

    bool ans = true;
    ASSERT_EQ(sol.isMatch(s, p), ans);
}

TEST(IsMatch, Example3) {
    Solution sol;
    string s = "aa";
    string p = ".*";

    bool ans = true;
    ASSERT_EQ(sol.isMatch(s, p), ans);
}
