/*
* Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2. 
* You have the following three operations permitted on a word:
*
* Insert a character
* Delete a character
* Replace a character
*
* https://leetcode.com/problems/edit-distance/description/
*/

#include <gtest/gtest.h>

#include <vector>
using namespace std;
/*
    Given 2 strings, return minimum number of operations to convert word1 to word2

    Naive: check all possible edit sequences & choose shortest one
    Optimal: DP, if chars at i & j same, no operations needed, else 3 cases:
    (1) replace (i - 1, j - 1), (2) delete (i - 1, j), (3) insert (i, j - 1)

    Time: O(m x n)
    Space: O(m x n)
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty() && word2.empty()) { return 0; }
        if (word1.empty() || word2.empty()) { return 1; }

        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // base cases (convert to empty string w/ deletions), dist is just length
        for (int i = 1; i <= m; i++) { dp[i][0] = i; }
        for (int j = 1; j <= n; j++) { dp[0][j] = j; }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // no operation needed, same char
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // min(replace, delete, insert) + 1 <-- since an op was needed
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }

        return dp[m][n];
    }
};

TEST(MinDistance, Example1) {
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";
    int ans = 3;

    ASSERT_EQ(sol.minDistance(word1, word2), ans);
}

TEST(MinDistance, Example2) {
    Solution sol;
    string word1 = "intention";
    string word2 = "execution";
    int ans = 5;

    ASSERT_EQ(sol.minDistance(word1, word2), ans);
}
