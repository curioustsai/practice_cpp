/*
Given a string s, return the longest palindromic substring in s.
*/

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    // https://leetcode.com/problems/longest-palindromic-substring/discuss/2923/Simple-C%2B%2B-solution-(8ms-13-lines)
    string longestPalindrome(string s) {
        if (s.length() <= 1) return "";

        int begin = 0;
        int strlen = 0;
        int i = 0;

        while (i < s.length()) {
            int left = i;
            int right = i;

            // find the middle point
            while (right < s.length() && s[right] == s[right + 1]) right++;
            i = right + 1;

            // expand out
            while (right < s.length() - 1 && left > 0 && s[left - 1] == s[right + 1]) {
                right++;
                left--;
            }

            if (right - left + 1 > strlen) {
                strlen = right - left + 1;
                begin = left;
            }
        }

        return s.substr(begin, strlen);
    }
};

TEST(VadlidPalindrome, Example1) {
    Solution sol;
    string input = "babad";
    string output = "bab";

    ASSERT_EQ(sol.longestPalindrome(input), output);
}

TEST(VadlidPalindrome, Example2) {
    Solution sol;
    string input = "cbbd";
    string output = "bb";

    ASSERT_EQ(sol.longestPalindrome(input), output);
}
