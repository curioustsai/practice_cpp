/*
Given a string s, return the longest palindromic substring in s.

Solution:
https://leetcode.com/problems/longest-palindromic-substring/discuss/2923/Simple-C%2B%2B-solution-(8ms-13-lines)
*/

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
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

    string longestPalindrome2(string s) { 
        int start = 0;
        int length = 1;
        
        for (int i = 0; i < s.size() - 1; i++) {
            middleOut(s, i, i, start, length);
            middleOut(s, i, i+1, start, length);
        }

        return s.substr(start, length);
    }

    void middleOut(string s, int left, int right, int& start, int& length) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        if (right - left - 1 > length) {
            start = left + 1;
            length = right - left - 1;
        }
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
