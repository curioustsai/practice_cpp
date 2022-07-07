/*
A message containing letters from A-Z can be encoded into numbers using the following mapping:
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"

To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.
*/

#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    // https://leetcode.com/problems/decode-ways/discuss/30451/Evolve-from-recursion-to-dp
    int numDecodings(string s) { return s.empty() ? 0 : numDecodings(0, s); }

    int numDecodings(int p, string& s) {
        int n = s.size();
        if (p == n) return 1;
        if (s[p] == '0') return 0;
        int res = numDecodings(p + 1, s);
        if (p < n - 1 && (s[p] == '1' || (s[p] == '2' && s[p + 1] < '7')))
            res += numDecodings(p + 2, s);
        return res;
    }
};

TEST(HouseRobber, Example1) {
    Solution sol;
    string input = "12";
    int ans = 2;

    ASSERT_EQ(sol.numDecodings(input), ans);
}

TEST(HouseRobber, Example2) {
    Solution sol;
    string input = "226";
    int ans = 3;
    ASSERT_EQ(sol.numDecodings(input), ans);
}
