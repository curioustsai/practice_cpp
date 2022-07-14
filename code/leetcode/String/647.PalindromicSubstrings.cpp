/*
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Solution:
https://leetcode.com/problems/palindromic-substrings/discuss/105689/Java-solution-8-lines-extendPalindrome
*/

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int counter = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            //odd length
            for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; l--, r++) { counter++; }

            //even length
            for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) { counter++; }
        }
        return counter;
    }
};

TEST(PalindromicSubstrings, Example1) {
    Solution sol;
    string input = "abc";
    int output = 3;

    ASSERT_EQ(sol.countSubstrings(input), output);
}

TEST(PalindromicSubstrings, Example2) {
    Solution sol;
    string input = "aaa";
    int output = 6;

    ASSERT_EQ(sol.countSubstrings(input), output);
}
