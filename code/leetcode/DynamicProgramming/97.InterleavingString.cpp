/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
substrings
 respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

https://leetcode.com/problems/interleaving-string/description/
*/

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (s3.size() != m + n) return false;

        return dfs(s1, s2, s3, 0, 0);
    }

private:
    map<pair<int, int>, bool> dp;
    bool dfs(string s1, string s2, string s3, int i, int j) {
        if (i == s1.size() && j == s2.size()) return true;

        if (dp.find({i, j}) != dp.end()) return dp[{i, j}];

        if (i < s1.size() && s1[i] == s3[i + j] && dfs(s1, s2, s3, i + 1, j)) return true;
        if (j < s2.size() && s2[j] == s3[i + j] && dfs(s1, s2, s3, i, j + 1)) return true;

        dp[{i, j}] = false;
        return dp[{i, j}];
    }
};

TEST(InterLeavString, Example1) {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    bool ans = true;
    Solution sol;
    ASSERT_EQ(sol.isInterleave(s1, s2, s3), ans);
}

TEST(InterLeavString, Example2) {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbbaccc";
    bool ans = false;
    Solution sol;
    ASSERT_EQ(sol.isInterleave(s1, s2, s3), ans);
}

TEST(InterLeavString, Example3) {
    string s1 = "";
    string s2 = "";
    string s3 = "";
    bool ans = true;
    Solution sol;
    ASSERT_EQ(sol.isInterleave(s1, s2, s3), ans);
}
