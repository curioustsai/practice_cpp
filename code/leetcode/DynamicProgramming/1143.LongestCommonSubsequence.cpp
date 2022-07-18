/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

https://leetcode.com/problems/longest-common-subsequence/
*/

#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    /*
    solution
    https://leetcode.com/problems/longest-common-subsequence/discuss/348884/C%2B%2B-with-picture-O(nm)
    */
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[m][n];
    };
};

TEST(LongestCommonSubsequence, ExampleI) {
    Solution sol;
    string text1 = "abcde", text2 = "ace";
    int ans = 3;

    ASSERT_EQ(sol.longestCommonSubsequence(text1, text2), ans);
}

TEST(LongestCommonSubsequence, ExampleII) {
    Solution sol;
    string text1 = "abc", text2 = "abc";
    int ans = 3;

    ASSERT_EQ(sol.longestCommonSubsequence(text1, text2), ans);
}

TEST(LongestCommonSubsequence, ExampleIII) {
    Solution sol;
    string text1 = "abc", text2 = "def";
    int ans = 0;

    ASSERT_EQ(sol.longestCommonSubsequence(text1, text2), ans);
}
